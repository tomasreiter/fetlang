#include "Tokenizer.h"
#include "FetlangManager.h"
#include "FractionParser.h"


Tokenizer::Tokenizer(){}

std::vector<Token> Tokenizer::splitCode(const std::string& code) const{
	std::vector<Token> tokens;
	std::string token = "";
	// Record line number 
	int line = 1;// The convention is to start at 1
	int parenthesis_on = 0; // Are we in parenthetical commment?

	
	for(int i=0;code[i]!='\0';i++){
		if(code[i] == '\n'){
			line++;
		}else if(code[i] == '('){
			tokens.push_back(Token("(", line));
			parenthesis_on = true;
		}else if(code[i] == ')'){
			if(!parenthesis_on){
				throw TokenizerException(line, "Did not expect ')' at this time (not in a comment)");
			}
			tokens.push_back(Token(")", line));
			parenthesis_on = false;
			
		}else if(parenthesis_on == false){
			if(code[i] == '"'){
				/* Chain literal */
				//Record whole chain
				do {
					if(code[i]=='\n')line++;/*Allow for multiline literals*/
					// Deal with backslash quotes
					if(code[i]=='\\' && code[i+1]=='\"'){
						token+="\"";
						i+=1;
					}else{
						token+=code[i];
					}
				//Check for end of chain
				i++;}while(code[i]!='\0' && code[i]!='"');
				if(code[i]=='\0'){/*Raise error upon unfinished quote*/};
				token+='"';
				tokens.push_back(Token(token, line));
				token="";
			
				
			}else if(! isspace(code[i]) && code[i]!='"'/*We have to add this last part just in case gag is on to avoid a potential segfault */){
				/* Identifier, keyword, fraction literal etc */
				//Record whole word until whitespace or start of quote or end of string
				// or a parenthesis
				while(!isspace(code[i]) && code[i] != '(' && code[i] != ')' && code[i]!='"' && code[i]!='\0'){
					token += code[i];
				i++;}i--;
				tokens.push_back(Token(token, line)); 
				token = ""; // Make clean for next time
			
			}
		}
	}

	return tokens;
}

std::vector<Token> Tokenizer::removeGags(const std::vector<Token>& tokens) const{
	std::vector<Token> new_tokens;
	bool parenthesis_on = false;
	for(Token token : tokens){
		if(token.isNullToken()){
			throw TokenizerException("Encountered NULL token while removing gags");
		}
	
		// Non-nesting
		if(token.getValue() == "("){
			parenthesis_on = true;
		}else if(token.getValue() == ")") {
			parenthesis_on = false;
			continue;
		}

		if(!parenthesis_on){
			new_tokens.push_back(token);
		}

	}
	return new_tokens;
}

/*
	Since both keywords and identifiers can be more than one word, this is slightly tricky

	If we come across part of a keyphrase, we check ahead to find the longest valid keyphrase
	if no valid keyphrase is found, that word ends up being part of an identifier (either continuing or starting)
*/

std::vector<Token> Tokenizer::mergeTokens(const std::vector<Token>& tokens) const{
	// This is used in the subsequent nested loops
	// List of potential phrases like ["is","is dominant", "is dominant towards"]
	// Farthest valid phrase to the right is selected as the keyphrase
	std::vector<std::string> potential_phrases;

	// Function return value
	std::vector<Token> new_tokens;

	const int tokens_size = tokens.size();	
	for(int i=0; i<tokens_size; i++){
		if(tokens[i].isNullToken()){
			throw TokenizerException("Encountered NULL token while merging tokens");
		}
		if(manager.isPartOfKeyphrase(tokens[i].getValue())){
			// Current token is a keyword
			int last_valid_phrase = -1;
			potential_phrases.clear();
			potential_phrases.push_back(tokens[i].getValue());
			int j;
							  //Also have to make sure it's all on the same line :P
			for(j = 0; j<manager.getMaxKeyphraseSize() && (tokens[i].getLine() == tokens[i+j].getLine()); j++){
				if(i+j >= tokens_size){
					break;
				}
				// Chain words into phrases
				if(j>0){
					potential_phrases.push_back(potential_phrases.back() +" "+tokens[i+j].getValue());
				}
				if(manager.isKeyphrase(potential_phrases[j])){
					// Current phrase is a keyphrase, so take note
					last_valid_phrase = j;
				}
			}
			
			if(last_valid_phrase!=-1){
				// Yay! Phrase is valid, add it to new_tokens!
				Token token(potential_phrases[last_valid_phrase], tokens[i].getLine());
				token.setCategory(Token::KEYPHRASE_TOKEN);
				new_tokens.push_back(token);

				// Don't forget to forward past phrase before continuing 
				i = i + last_valid_phrase;
			
				continue;
			}
			// Or not...

		}
		
		// Current token is NOT part of a keyphrase
		// So then what kind of token is it? :O

		Token token = Token(tokens[i].getValue(), tokens[i].getLine());

		if(tokens[i].getValue().length()<=0){
			TokenizerException(tokens[i].getLine(), "Token has null value");
		}

		// Could it be a chain literal!?
		if(tokens[i].getValue()[0] == '"'){
			token.setCategory(Token::CHAIN_LITERAL_TOKEN);
		// Or maybe a fraction literal?
		}else if(FractionParser::startsFractionLiteral(tokens[i].getValue())){
			// Collect the whole fraction string
			std::string fraction_string = tokens[i].getValue();
			while(i+1 < tokens_size && FractionParser::partOfFractionLiteral(tokens[i+1].getValue())){
				fraction_string += " " + tokens[i+1].getValue();
				i++;
			}

			// Raise exceptions if you got 'em
			FractionParser::stringToFraction(fraction_string);

			token = Token(fraction_string, tokens[i].getLine());
			token.setCategory(Token::FRACTION_LITERAL_TOKEN);
		}
		else{
			// Not a keyphrase or a chain or a fraction? Guess it's an identifier!
			// But, what if there was an identifier before it on the same line? Then combine them :O
			const auto new_tokens_size = new_tokens.size();
			if((new_tokens_size > 0) && (new_tokens[new_tokens_size - 1].getCategory() == Token::IDENTIFIER_TOKEN) && (new_tokens[new_tokens_size - 1].getLine() == tokens[i].getLine())){
				// Now kiss(concat tokens)
				new_tokens[new_tokens_size - 1] = Token(new_tokens[new_tokens_size - 1].getValue() +" "+ tokens[i].getValue(), tokens[i].getLine());
				new_tokens[new_tokens_size -1].setCategory(Token::IDENTIFIER_TOKEN);
				continue;
			}else{
				// Nvm - just make a new token
				token.setCategory(Token::IDENTIFIER_TOKEN);
			}
		}

		// Cool, it's a valid token now, just add it friend
		new_tokens.push_back(token);
	
	}
	

	return new_tokens;
}
		
		
inline static bool tokenIsPossessivePronoun(const Token& t){
	if(t.getCategory() == Token::KEYPHRASE_TOKEN && t.getKeyphraseCategory() == PRONOUN_KEYPHRASE){
		return manager.getPronoun(t.getValue()).isPossessive();
	}
	return false;
}
std::vector<Token> Tokenizer::removePossessions(const std::vector<Token>& old_tokens){
	try{
		std::vector<Token> tokens;
		for(auto it = old_tokens.begin(); it != old_tokens.end(); it++){
			tokens.push_back(*it);
			if(it->getCategory() == Token::IDENTIFIER_TOKEN){
				// Identifier, so remove everything after ' character
				if(it->getValue().find("\'") != std::string::npos){
					tokens.back().setValue(it->getValue().substr(0, it->getValue().find("\'")));
				}
			}else if(tokenIsPossessivePronoun(*it)){
				
				// Possessive pronoun, so elimanate following identifiers
				int have_skipped = false;
				if(it->getValue() == "her"){
					have_skipped = true;// Because "her" can be possessive or not
				}
				while ((it+1) != old_tokens.end() && (it+1)->getCategory() == Token::IDENTIFIER_TOKEN){
					// Must be on the same line
					if(it->getLine() != (it+1)->getLine()) break;
		
					it++;
					have_skipped=true;
				}
				
			}
			
		}
		return tokens;
	}catch(const FetlangException&){
		throw;
	}catch(const std::exception& e){
		throw std::runtime_error(std::string("Well, removePossessions is broken: ")+e.what());
	}
}
			
			
			
/*			

		auto tokens = removePossessions(
						mergeTokens(
							removeGags(
								splitCode(code)
							)
						)
					);
*/


std::vector<Token> Tokenizer::tokenize(const std::string& code){
	return removePossessions(
				mergeTokens(
					removeGags(
						splitCode(code)
					)
				)
			);
}
	