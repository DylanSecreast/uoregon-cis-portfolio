#include <stdlib.h>
#include <stdio.h>
#define NUM_INTS 4
int main(void){
    int * int_block = malloc(NUM_INTS * sizeof(int) );
    
    for(int i = 0; i <  NUM_INTS; i++)
         int_block[i]= i;

    return 0;
}