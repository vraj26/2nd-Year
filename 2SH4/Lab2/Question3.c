#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


// this is the very first question without hints in the comments.  read the manual to develop your own algorithm

// Read Questions.h to understand the definition of Q3Struct

void efficient(const int source[], struct Q3Struct effVector[], int size)
{
    int index = 0;
    for(int pos = 0; pos < size; pos++){
        if(source[pos] != 0){
            effVector[index].val = source[pos];
            effVector[index].pos = pos;
            index++;
        }
    }

}

void reconstruct(int source[], int m, const struct Q3Struct effVector[], int n)
{

    //important to init to zero
    for(int i = 0; i < m; i++){
        source[i] = 0;
    }

    for(int i = 0; i < n; i++){
        source[effVector[i].pos] = effVector[i].val;
    }
}
