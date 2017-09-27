#include "linkedList.h" 
#include <stdio.h> 
#include <string.h> 

int main(int argc, char *argv[]) { 

 LinkedList * l;
 
    if (! (l = list_create())) { 
        fprintf(stderr, "Unable to create Linked list\n"); 
        return -2; 
    }
   

    

    int i;
    for( i = 0; i < 10; i++){

          list_add(l, i);
    }

    display(l);

    list_destroy(l);

    return 0;
 
}
