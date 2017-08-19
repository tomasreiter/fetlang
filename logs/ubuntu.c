/* Generated by Fetlang */
#include <stdio.h>
#include "core/include/compatibility.h"
#include "core/include/error.h"
#include "core/include/typedefs.h"
#include "core/include/fraction_math.h"
#include "core/include/chain.h"
#include "core/include/fraction.h"
#include "assertiveness/include/assert.h"
int main(int argc, char* argv[]){
/* Initializing variables */
Fraction fetvar_15_0;
fetvar_15_0.num = 0;
fetvar_15_0.den = 1;
Fraction fetvar_16_1;
fetvar_16_1.num = 0;
fetvar_16_1.den = 1;
Fraction fetvar_17_2;
fetvar_17_2.num = 0;
fetvar_17_2.den = 1;
Fraction fetvar_18_3;
fetvar_18_3.num = 0;
fetvar_18_3.den = 1;
Fraction fetvar_19_4;
fetvar_19_4.num = 0;
fetvar_19_4.den = 1;
Fraction fetvar_20_5;
fetvar_20_5.num = 0;
fetvar_20_5.den = 1;
Fraction fetvar_21_6;
fetvar_21_6.num = 0;
fetvar_21_6.den = 1;
Fraction fetvar_22_7;
fetvar_22_7.num = 0;
fetvar_22_7.den = 1;
Fraction fetvar_23_alice;
fetvar_23_alice.num = 0;
fetvar_23_alice.den = 1;
Fraction fetvar_24_bob;
fetvar_24_bob.num = 0;
fetvar_24_bob.den = 1;
Chain fetvar_27_chain;
init_chain(&fetvar_27_chain);
Fraction fetvar_25_charlie;
fetvar_25_charlie.num = 0;
fetvar_25_charlie.den = 1;
Chain fetvar_31_contents;
init_chain(&fetvar_31_contents);
Fraction fetvar_26_count;
fetvar_26_count.num = 0;
fetvar_26_count.den = 1;
Chain fetvar_30_filename;
init_chain(&fetvar_30_filename);
Chain fetvar_29_hello;
init_chain(&fetvar_29_hello);
Link* fetvar_28_reference = NULL;

Fraction argc_fraction = construct_fraction(argc, 1);
Chain argv_chain;
init_chain(&argv_chain);for(int i=0;i<argc;i++){append_cstr_to_chain(&argv_chain, argv[i]); append_flink_to_chain(&argv_chain, construct_fraction(0,1));}
do{
fetvar_15_0=add_fractions(fetvar_15_0, construct_fraction(0, 1));

fetvar_16_1=add_fractions(fetvar_16_1, construct_fraction(1, 1));

fetvar_17_2=add_fractions(fetvar_17_2, construct_fraction(2, 1));

fetvar_18_3=add_fractions(fetvar_18_3, construct_fraction(3, 1));

fetvar_19_4=add_fractions(fetvar_19_4, construct_fraction(4, 1));

fetvar_20_5=add_fractions(fetvar_20_5, construct_fraction(5, 1));

fetvar_21_6=add_fractions(fetvar_21_6, construct_fraction(6, 1));

fetvar_22_7=add_fractions(fetvar_22_7, construct_fraction(7, 1));

fetvar_23_alice=add_fractions(fetvar_23_alice, construct_fraction(5, 1));

fetvar_24_bob=add_fractions(fetvar_24_bob, construct_fraction(4, 1));

fetvar_25_charlie=add_fractions(fetvar_25_charlie, construct_fraction(4, 1));

fetlang_assert(compare_fractions(fetvar_23_alice, fetvar_24_bob) == 1, "assertion of dominance failed");;

fetlang_assert(!compare_fractions(fetvar_24_bob, fetvar_25_charlie), "assertion of equality between fractions failed");;

fetvar_23_alice=multiply_fractions(fetvar_23_alice, construct_fraction(0, 1));

fetvar_24_bob=multiply_fractions(fetvar_24_bob, construct_fraction(0, 1));

fetvar_25_charlie=multiply_fractions(fetvar_25_charlie, construct_fraction(0, 1));

fetvar_23_alice=subtract_fractions(fetvar_23_alice, construct_fraction(5, 1));

fetvar_24_bob=subtract_fractions(fetvar_24_bob, construct_fraction(4, 1));

fetvar_25_charlie=subtract_fractions(fetvar_25_charlie, construct_fraction(4, 1));

fetlang_assert(compare_fractions(fetvar_24_bob, fetvar_23_alice) == 1, "assertion of dominance failed");;

fetlang_assert(!compare_fractions(fetvar_24_bob, fetvar_25_charlie), "assertion of equality between fractions failed");;

fetvar_23_alice=multiply_fractions(fetvar_23_alice, construct_fraction(0, 1));

fetvar_24_bob=multiply_fractions(fetvar_24_bob, construct_fraction(0, 1));

fetvar_25_charlie=multiply_fractions(fetvar_25_charlie, construct_fraction(0, 1));

fetvar_23_alice=subtract_fractions(fetvar_23_alice, construct_fraction(5, 1));

fetvar_23_alice=multiply_fractions(fetvar_23_alice, construct_fraction(5, 1));

fetvar_24_bob=subtract_fractions(fetvar_24_bob, construct_fraction(25, 1));

fetlang_assert(!compare_fractions(fetvar_24_bob, fetvar_23_alice), "assertion of equality between fractions failed");;

fetvar_23_alice=multiply_fractions(fetvar_23_alice, construct_fraction(0, 1));

fetvar_24_bob=multiply_fractions(fetvar_24_bob, construct_fraction(0, 1));

fetvar_25_charlie=multiply_fractions(fetvar_25_charlie, construct_fraction(0, 1));

fetlang_assert(!compare_fractions(fetvar_23_alice, fetvar_15_0), "assertion of equality between fractions failed");;

fetvar_23_alice=divide_fractions(fetvar_23_alice, construct_fraction(9, 1));

fetlang_assert(!compare_fractions(fetvar_23_alice, fetvar_15_0), "assertion of equality between fractions failed");;

fetvar_23_alice=add_fractions(fetvar_23_alice, construct_fraction(100, 1));

fetvar_23_alice=divide_fractions(fetvar_23_alice, construct_fraction(20, 1));

fetlang_assert(!compare_fractions(fetvar_23_alice, fetvar_20_5), "assertion of equality between fractions failed");;

fetvar_23_alice=multiply_fractions(fetvar_23_alice, construct_fraction(0, 1));

fetvar_24_bob=multiply_fractions(fetvar_24_bob, construct_fraction(0, 1));

fetvar_25_charlie=multiply_fractions(fetvar_25_charlie, construct_fraction(0, 1));

fetvar_23_alice=add_fractions(fetvar_23_alice, construct_fraction(203, 1));

fetvar_24_bob=add_fractions(fetvar_24_bob, construct_fraction(5, 1));

fetvar_25_charlie=add_fractions(fetvar_25_charlie, construct_fraction(3, 1));

fetvar_23_alice=modulus_fractions(fetvar_23_alice, fetvar_24_bob);

fetlang_assert(!compare_fractions(fetvar_23_alice, fetvar_25_charlie), "assertion of equality between fractions failed");;

fetvar_26_count=add_fractions(fetvar_26_count, construct_fraction(0, 1));

/* Chain literal initialization */
Chain temp_chain_1804289383;
init_chain(&temp_chain_1804289383);
append_cstr_to_chain(&temp_chain_1804289383, "012");

clear_chain(&fetvar_27_chain); append_chain_to_chain(&fetvar_27_chain, temp_chain_1804289383);

/* Chain literal deconstruction */
clear_chain(&temp_chain_1804289383);

/* Bondage */
fetvar_28_reference = fetvar_27_chain.start;
while(fetvar_28_reference != NULL){
fetvar_28_reference=fetvar_28_reference->next;}fetvar_28_reference=fetvar_27_chain.start;


(*fetvar_28_reference).value=subtract_fractions((*fetvar_28_reference).value, construct_fraction(48, 1));

if(((compare_fractions(fetvar_26_count, fetvar_15_0)==0))){
}
fetlang_assert(!compare_fractions((*fetvar_28_reference).value, fetvar_15_0), "assertion of equality between fractions failed");;

if(((compare_fractions(fetvar_26_count, fetvar_16_1)==0))){
}
fetlang_assert(!compare_fractions((*fetvar_28_reference).value, fetvar_16_1), "assertion of equality between fractions failed");;

if(((compare_fractions(fetvar_26_count, fetvar_17_2)==0))){
fetlang_assert(!compare_fractions((*fetvar_28_reference).value, fetvar_17_2), "assertion of equality between fractions failed");;

fetvar_26_count=add_fractions(fetvar_26_count, construct_fraction(1, 1));

fetlang_assert(!compare_fractions((*fetvar_28_reference).value, fetvar_15_0), "assertion of equality between fractions failed");;

/* Bondage */
fetvar_28_reference = fetvar_27_chain.start;
while(fetvar_28_reference != NULL){
if(((compare_fractions(fetvar_26_count, fetvar_15_0)==0))){
}
fetvar_28_reference=fetvar_28_reference->next;}fetvar_28_reference=fetvar_27_chain.start;


fetlang_assert(!compare_fractions((*fetvar_28_reference).value, fetvar_15_0), "assertion of equality between fractions failed");;

}
if(((compare_fractions(fetvar_26_count, fetvar_16_1)==0))){
}
fetlang_assert(!compare_fractions((*fetvar_28_reference).value, fetvar_16_1), "assertion of equality between fractions failed");;

if(((compare_fractions(fetvar_26_count, fetvar_17_2)==0))){
}
fetlang_assert(!compare_fractions((*fetvar_28_reference).value, fetvar_17_2), "assertion of equality between fractions failed");;

fetvar_26_count=add_fractions(fetvar_26_count, construct_fraction(1, 1));

/* Chain literal initialization */
Chain temp_chain_846930886;
init_chain(&temp_chain_846930886);
append_cstr_to_chain(&temp_chain_846930886, "That's *burp* right, they blew up");

clear_chain(&fetvar_29_hello); append_chain_to_chain(&fetvar_29_hello, temp_chain_846930886);

/* Chain literal deconstruction */
clear_chain(&temp_chain_846930886);

/* Chain literal initialization */
Chain temp_chain_1681692777;
init_chain(&temp_chain_1681692777);
append_cstr_to_chain(&temp_chain_1681692777, "test.txt");

clear_chain(&fetvar_30_filename); append_chain_to_chain(&fetvar_30_filename, temp_chain_1681692777);

/* Chain literal deconstruction */
clear_chain(&temp_chain_1681692777);

write_chain_to_file(fetvar_29_hello, fetvar_30_filename);

read_file_to_chain(&fetvar_31_contents, fetvar_30_filename);;

fetlang_assert(!compare_chains(fetvar_31_contents, fetvar_29_hello), "assertion of equality between chains failed");;

/* Safeword called */
break;
/* Stream chain(lho) initialization */
Chain temp_lho_stream_chain_1714636915;
init_chain(&temp_lho_stream_chain_1714636915);
append_stream_to_chain(&temp_lho_stream_chain_1714636915, stderr);

/* Chain literal initialization */
Chain temp_chain_1957747793;
init_chain(&temp_chain_1957747793);
append_cstr_to_chain(&temp_chain_1957747793, "Safeword was not obeyed");

clear_chain(&temp_lho_stream_chain_1714636915);append_chain_to_chain(&temp_lho_stream_chain_1714636915, temp_chain_1957747793);append_flink_to_chain(&temp_lho_stream_chain_1714636915, construct_fraction(10,1));;

/* Stream chain deconstruction */
chain_to_stream(temp_lho_stream_chain_1714636915, stderr);
clear_chain(&temp_lho_stream_chain_1714636915);

/* Chain literal deconstruction */
clear_chain(&temp_chain_1957747793);

fetlang_assert(!compare_fractions(fetvar_15_0, fetvar_16_1), "assertion of equality between fractions failed");;

}while(0);
clear_chain(&argv_chain);/* Deconstructing variables */
clear_chain(&fetvar_27_chain);
clear_chain(&fetvar_31_contents);
clear_chain(&fetvar_30_filename);
clear_chain(&fetvar_29_hello);

/* Finished */
return 0;
}