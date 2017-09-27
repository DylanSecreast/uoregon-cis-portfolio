#include <stdlib.h>
#include <stdio.h>
#define NUM_INTS 4

int main(void)
{


    int * int_block = malloc(NUM_INTS * sizeof(int) );
    
    for(int i = 0; i <  NUM_INTS; i++)
         int_block[i]= i;
     
    printf("The %dth int is %d\n",NUM_INTS, int_block[NUM_INTS]);
    
    printf("The -1st int is %d\n", int_block[-1]);
    
    free( int_block);
    
}