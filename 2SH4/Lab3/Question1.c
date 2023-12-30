#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"


int my_strlen(const char * const str1)
{
	// Returns the length of the string - the number of characters, but IGNORING the terminating NULL character
	int i = 0;
	while(str1[i] != '\0'){
		i++;
	}
	return i;
	
}

int my_strcmp(const char * const str1, const char * const str2)
{
	// Return 0 if the two strings are not identical.  Return 1 otherwise.
	
	// Criteria 1: Check their lenghts.  If not the same length, not equal

	// Criteria 2: Check their contents char-by-char.  If mismatch found, not equal

	// if passing the two criteria, strings equal
	int i = 0;
	if(my_strlen(str1) != my_strlen(str2)){
		return 0;
	}
	while(str1[i] != '\0' && str2[i] != '\0'){
		if(str1[i] != str2[i]){
			return 0;
		}
		i++;
	}
	return 1;
}


int my_strcmpOrder(const char * const str1, const char * const str2)
{
	/*compare_str alphabetically compares two strings.
    	If str2 is alphabetically smaller than str1 (comes before str1),
    	the function returns a 1, else if str1 is smaller than str2, the
    	function returns a 0.*/
	int i =0;
	while(str1[i] != '\0' && str2[i] != '\0'){
		if(str1[i] < str2[i]){
			return 0;
		} else if (str1[i] > str2[i]){
			return 1;
		}
		i++;
	}
	// if two strings are completely identical in order, return -1.
	if(my_strcmp(str1, str2)){
		return -1;
	}
	// We are NOT looking for any custom alphabetical order - just use the integer values of ASCII character

	
}


char *my_strcat(const char * const str1, const char * const str2){

	/* this is the pointer holding the string to return */
	
	char *z = NULL;
	
	/*write your implementation here*/
	z = (char*)malloc(my_strlen(str1) + my_strlen(str2) + 1);

	if (z){
		for(int i = 0 ; i < my_strlen(str1); i++){
			z[i] = str1[i];
		}

		for(int i = 0 ; i < my_strlen(str2); i++){
			z[my_strlen(str1) + i] = str2[i];
		}

	}
	
	
	z[my_strlen(str1) + my_strlen(str2)] = '\0';


	/* finally, return the string*/
	return z;

	// IMPORTANT!!  Where did the newly allocated memory being released?
	// THINK ABOUT MEMORY MANAGEMENT
	
}