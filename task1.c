/* 
 *task1.c
 * Hannah Soria
 * 5/2/2024
 * testing average time per call to allocate different amount of memory
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "time.h"

int main(int argc, char *argv[]){

    // declare memory for variables small medium large with corresponding sizes
    int (**small) = (int**)malloc(1000*sizeof(int*));
    int (**medium) = (int**)malloc(10000*sizeof(int*));
    int (**large) = (int**)malloc(1000000*sizeof(int*));

    // small variable with 200 calls
    double time_1 = time_sec(); // time collected
    for (int i=0; i<200;i++){ // loop through 200 
        small[i] = (int*)malloc(200000*sizeof(int*)); // malloc memory for each iteration
    }

    double time_2 = time_sec(); // time collected
    double small_total = time_2 - time_1; // find total
    printf("total time for small with 200 iterations: %f\n", small_total); // print the result

    for (int i=0; i<200;i++){ // free memory
        free(small[i]);
    }

    double time_17 = time_sec(); // time collected
    for (int i=0; i<1000;i++){ // loop through 2000
        small[i] = (int*)malloc(1000000*sizeof(int*)); // malloc memory for each iteration
    }

    //small variable for 1000 
    double time_18 = time_sec(); // time collected
    double small_total3 = time_18 - time_17; // find total
    printf("total time for small with 1,000 iterations: %f\n", small_total3); // print the result

    for (int i=0; i<1000;i++){ // loop through 2000
        free(small[i]); // malloc memory for each iteration
    }

    //small variable for 2000 
    double time_3 = time_sec(); // time collected
    for (int i=0; i<2000;i++){ // loop through 2000
        small[i] = (int*)malloc(2000000*sizeof(int*)); // malloc memory for each iteration
    }

    double time_4 = time_sec(); // time collected
    double small_total2 = time_4 - time_3; // find total
    printf("total time for small with 2,000 iterations: %f\n", small_total2); // print the result

    for (int i=0; i<2000;i++){ // loop through 2000
        free(small[i]); // malloc memory for each iteration
    }

/*-------------------------------------------------------------------------------------------*/

    // med variable with 200 calls
    double time_5 = time_sec(); // time collected
    for (int i=0; i<200;i++){ // loop through 200 
        medium[i] = (int*)malloc(2000000*sizeof(int*)); // malloc memory for each iteration
    }

    double time_6 = time_sec(); // time collected
    double med_total = time_6 - time_5; // find total
    printf("total time for medium with 200 iterations: %f\n", med_total); // print the result

    for (int i=0; i<200;i++){ // free memory
        free(medium[i]);
    }

    double time_13 = time_sec(); // time collected
    for (int i=0; i<1000;i++){ // loop through 2000
        medium[i] = (int*)malloc(10000000*sizeof(int*)); // malloc memory for each iteration
    }

    //medium variable for 1000 
    double time_14 = time_sec(); // time collected
    double medium_total3 = time_14 - time_13; // find total
    printf("total time for medium with 1,000 iterations: %f\n", medium_total3); // print the result

    for (int i=0; i<1000;i++){ // loop through 2000
        free(medium[i]); // malloc memory for each iteration
    }

    //medium variable for 2000 
    double time_7 = time_sec(); // time collected
    for (int i=0; i<2000;i++){ // loop through 2000
        medium[i] = (int*)malloc(20000000*sizeof(int*)); // malloc memory for each iteration
    }

    double time_8 = time_sec(); // time collected
    double med_total2 = time_8 - time_7; // find total
    printf("total time for medium with 2,000 iterations: %f\n", med_total2); // print the result

    for (int i=0; i<2000;i++){ // loop through 2000
        free(medium[i]); // malloc memory for each iteration
    }


/*-------------------------------------------------------------------------------------------*/

    // large variable with 200 calls
    double time_9 = time_sec(); // time collected
    for (int i=0; i<200;i++){ // loop through 200 
        large[i] = (int*)malloc(200000000*sizeof(int*)); // malloc memory for each iteration
    }

    double time_10 = time_sec(); // time collected
    double large_total = time_10 - time_9; // find total
    printf("total time for large with 200 iterations: %f\n", large_total); // print the result

    for (int i=0; i<200;i++){ // free memory
        free(large[i]);
    }

    //large variable for 1000 
    double time_15 = time_sec(); // time collected
    for (int i=0; i<1000;i++){ // loop through 2000
        large[i] = (int*)malloc(1000000000*sizeof(int*)); // malloc memory for each iteration
    }

    double time_16 = time_sec(); // time collected
    double large_total3 = time_16 - time_15; // find total
    printf("total time for large with 1,000 iterations: %f\n", large_total3); // print the result

    for (int i=0; i<1000;i++){ // loop through 2000
        free(large[i]); // malloc memory for each iteration
    }

    //small variable for 2000 
    double time_11 = time_sec(); // time collected
    for (int i=0; i<2000;i++){ // loop through 2000
        large[i] = (int*)malloc(2000000000*sizeof(int*)); // malloc memory for each iteration
    }

    double time_12 = time_sec(); // time collected
    double large_total2 = time_12 - time_11; // find total
    printf("total time for large with 2,000 iterations: %f\n", large_total2); // print the result

    for (int i=0; i<2000;i++){ // loop through 2000
        free(large[i]); // malloc memory for each iteration
    }

    free(small);
    free(medium);
    free(large);
}


