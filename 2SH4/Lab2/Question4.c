#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"

// Debugging Report Question
// 1 Syntatic Error - Fix it through compiler message
// 2 Semantic Errors, Debugger Report Required
// EVEN IF you see the error by code reading / by inspection, you need to still
//  1. Set up the breakpoint at the right place
//  2. Set up the watches over the relevant variables
//  3. Use stepping in debugger to show the exact moment where the bug occurs, and how it deviates from the expected behaviour
//  4. Show how your proposed fix defeats the bug.

void sortDatabyBubble(struct Q4Struct array[], int size)
{
    struct Q4Struct temp;
    temp.intData = 0;
    temp.charData = 0;

    int i;
    int curr, next;
    int done = 0;

    while (!done)
    {
        done = 1;

        for (i = 0; i < size - 1; i++)
        {
            curr = array[i].intData;
            next = array[i + 1].intData;

            // Swap two elements whenever current element value is larger than the value of the next element.
            if (curr > next)
            {
                temp.intData = array[i].intData;
                temp.charData = array[i].charData;

                array[i].intData = array[i + 1].intData;
                array[i].charData = array[i + 1].charData;

                array[i + 1].intData = temp.intData; // added semicolon for compilation
                array[i + 1].charData = temp.charData;

                done = 0;
            }
        }
    }
}

void sortDatabySelection(struct Q4Struct array[], int size)
{
    // Selection Sort is an alternative to Bubble Sort, with the intention to lower the number of swapping operations.

    // Read the lab manual to understand the general process of Selection Sort, then implement it here:

    // Step 1:  From the start of the array, visit every element
    // Step 2:  For every visited element at index i (current element), check all the subsequent elements *AFTER* index i.
    //          Find the element with the smallest value among the current element, and all the subsequent elements, and denote it as target element
    // Step 3:  If the target element is not the current element, swap the target element and the current element.
    // Step 4:  Move on to the next element, repeat Step 2 and 3.
    // When reaching the last element in the array, DONE.
    struct Q4Struct temp;
    temp.charData = 0;
    temp.intData = 0;
    int i, min_index;

    for (i = 0; i < size; i++)
    {
        min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j].intData < array[min_index].intData)
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            temp.intData = array[i].intData;
            temp.charData = array[i].charData;

            array[i].intData = array[min_index].intData;
            array[i].charData = array[min_index].charData;

            array[min_index].intData = temp.intData;
            array[min_index].charData = temp.charData;
        }
    }
}
