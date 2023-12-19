
#include "Questions.h"



int Q1_for(int num){
	int sum = 0;

	for(int i = num; i <= 1000; i+=num){
		sum += i;
	}

	return sum;
	/*
	// calculate your sum below..this has to use for loop

	for(int i = num; i < 1000; i)
		{
			sum += i;

			//code is almost done just figure out the extra number which goes above 1000 (VERY IMPORTANT)
		}

	// here, we return the calcualted sum:
	return sum;*/
}
int Q1_while(int num){
	int sum = 0;
	int i = num;

	while(i < 1000){
		sum += i;
		i += num;
	}

	return sum;
	/*int sum = 0;
	int i = 0;
	// calculate your sum below..this has to use while loop
	while (i < 1000)
    {
        i += num;
        sum += i;
    }


	
	// here, we return the calcualted sum:
	return sum;*/
}
int Q1_dowhile(int num){
	int sum = 0;
	int i = num;

	do {
		sum += i;
		i+=num;
	} while (i < 1000);

	return sum;
	/*int sum = 0;
	
	// calculate your sum below..this has to use do-while loop
	int i = 0;
	// calculate your sum below..this has to use do-while loop
	//it is adding an extra 1005 to the normal 1002, find out solution for both, focus on 1005 first
    do {
        i += num;
        sum += i;
    } while (i<1000);

	  
	
	// here, we return the calcualted sum:
	return sum;*/
}
//===============================================================================================
int Q2_FPN(float Q2_input, float Q2_threshold){
	
	int result;
	// Determine which range does Q2_input fall into.  Keep in mind the floating point number range.
	// Assign the correct output to the result.
	if((Q2_input >= Q2_threshold*-2) && (Q2_input < Q2_threshold*-1))
    {
        result = 0;
    } 
    else if ((Q2_input >= Q2_threshold*-1) && (Q2_input < 0))
    {
        result = 1;
    }
    else if ((Q2_input >= 0) && Q2_input < (Q2_threshold*1))
    {
        result = 2;
    }
    else if ((Q2_input >= Q2_threshold*1) && Q2_input <= (Q2_threshold*2))
    {
        result = 3;
    } 
    else
    {
        result = -999;
    }
	            
	


	// Finally, return the result.
	return result;
	            
	


	// Finally, return the result.
	return result;
}
//===============================================================================================
int Q3(int Q3_input, int perfect[]){
	
	
	
		//counts is the variable that should hold the total number of found perfect numbers
		//you should update it within your code and return it at the end
	    int counts= 0;

		for(int i = 1; i <= Q3_input; i++){
			int sum = 0;
			for (int j = 1; j<i; j++){
				if(i % j == 0){
					sum += j;
				}
			}
			if(sum == i){
				perfect[counts] = sum;
				counts ++;
			}
		}
		return counts;
		/*
		*
		*perfect is an array that you need to add into it any perfect number you find
		*which means at the end of this function, the perfect[] array should hold all the found perfect numbers in the range
		*you do not need to return perfect because as stated in lectures arrays are already passed by reference. so, modifying them will 
		*autmoatically reflect in the main calling function.
		*/

}
//===============================================================================================
int Q4_Bubble(int array[], int size){
	
	// This variable tracks the number of passes done on the array to sort the array.
	int passes = 0; 
	int flag;
	//incorporate some sort of flag to check when it is done

	for(int i = 0; i < size-1; i++){
		flag = 0;
		for(int j = 0; j < size-1; j++){
			if(array[j] > array[j+1]){
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}

		passes++;
	}

	// Finally, return the number of passes used to complete the Bubble Sort
	return passes;
	// Pseudocode
	// 	1. Given an array and its size, visit every single element in the array up to size-2 (i.e. up to the second last element, omit the last element)
	//  2. For every visited element (current element), check its subsequent element (next element).  
	//     If the next element is larger, swap the current element and the next element. 
	//  3. Continue until reaching size-2 element.  This is considered One Pass => increment pass count by one.
	//  4. Repeat 1-3 until encountering a pass in which no swapping was done.
	//   -> Sorting Completed.	
}