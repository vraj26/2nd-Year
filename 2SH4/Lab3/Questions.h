#include <stdio.h>
#include <stdlib.h>

//Question 1 definitions and prototypes
int my_strlen(const char * const str1);
int my_strcmp(const char * const str1, const char * const str2);
int my_strcmpOrder(const char * const str1, const char * const str2);
char *my_strcat(const char * const str1, const char * const str2);


//Question 2 definitions and prototypes
char **read_words(const char *input_filename, int *nPtr);
void swap(char **str1, char **str2);
void delete_wordlist(char **word_list, int size);
void sort_words_Bubble(char **words, int size);
void sort_words_Selection(char **words, int size);
