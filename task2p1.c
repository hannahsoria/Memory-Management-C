/* 
 * task2p1.c
 * Hannah Soria
 * 5/2/2024
 * showing c must allocate and deallocate memory
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(sizeof(int)); // allocate memory
    *ptr = 30;
    printf("the value of the pointer is %d\n", *ptr);
    free(ptr); // free the memory
    return 0;
}

