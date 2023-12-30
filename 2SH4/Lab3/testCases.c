#include <assert.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CuTest.h"
#include "Questions.h"
    


   
    
//=========Question 1==================================
	void TestQ1_strlen_case1(CuTest *tc)
	{
		char str[] = "This is a test!";
		int expected = 15;
		int actual = 0;

		actual = my_strlen(str);

		CuAssertIntEquals(tc, expected, actual);
	}
	
	void TestQ1_strlen_case2(CuTest *tc)
	{
		char str[] = "This is another test...";
		int expected = 23;
		int actual = 0;

		actual = my_strlen(str);

		CuAssertIntEquals(tc, expected, actual);
	}

	void TestQ1_strlen_case0(CuTest *tc)
	{
		char str[] = "";
		int expected = 0;
		int actual = 0;

		actual = my_strlen(str);

		CuAssertIntEquals(tc, expected, actual);
	}

	//my 2 new test cases
	void TestQ1_strlen_caseNew1(CuTest *tc)
	{
		char str[] = "Thi";
		int expected = 3;
		int actual = 0;

		actual = my_strlen(str);

		CuAssertIntEquals(tc, expected, actual);
	}

	void TestQ1_strlen_caseNew2(CuTest *tc)
	{
		char str[] = "Vraj Patel";
		int expected = 10;
		int actual = 0;

		actual = my_strlen(str);

		CuAssertIntEquals(tc, expected, actual);
	}





	void TestQ1_strcmp_caseEqual(CuTest *tc)
	{
		char str1[] = "This is a test!";
		char str2[] = "This is a test!";
		int expected = 1;
		int actual = 0;

		actual = my_strcmp(str1, str2);

		CuAssertIntEquals(tc, expected, actual);
	}

	void TestQ1_strcmp_caseUnequalLength(CuTest *tc)
	{
		char str1[] = "This is a test!";
		char str2[] = "This is a test! ";
		int expected = 0;
		int actual = 0;

		actual = my_strcmp(str1, str2);

		CuAssertIntEquals(tc, expected, actual);
	}

	void TestQ1_strcmp_caseUnequalContents(CuTest *tc)
	{
		char str1[] = "This is a test!";
		char str2[] = "This is a pass!";
		int expected = 0;
		int actual = 0;

		actual = my_strcmp(str1, str2);

		CuAssertIntEquals(tc, expected, actual);
	}

	void TestQ1_strcmp_caseEmpty(CuTest *tc)
	{
		char str1[] = "";
		char str2[] = "";
		int expected = 1;
		int actual = 0;

		actual = my_strcmp(str1, str2);

		CuAssertIntEquals(tc, expected, actual);
	}

	//my 2 new test cases
	void TestQ1_strcmp_caseNew1(CuTest *tc)
	{
		char str1[] = "HEYYYYY";
		char str2[] = "HEYY";
		int expected = 0;
		int actual = 0;

		actual = my_strcmp(str1, str2);

		CuAssertIntEquals(tc, expected, actual);
	}

	void TestQ1_strcmp_caseNew2(CuTest *tc)
	{
		char str1[] = "wassssup";
		char str2[] = "wassssup";
		int expected = 1;
		int actual = 0;

		actual = my_strcmp(str1, str2);

		CuAssertIntEquals(tc, expected, actual);
	}










	void TestQ1_strcmpOrder_caseSmaller(CuTest *tc)
	{
		char str1[] = "Absolutely";
		char str2[] = "new start";
		int expected = 0;
		int actual = 0;

		actual = my_strcmpOrder(str1, str2);

		CuAssertIntEquals(tc, expected, actual);
	}

	void TestQ1_strcmpOrder_caseLarger(CuTest *tc)
	{
		char str1[] = "more than";
		char str2[] = "an apple";
		int expected = 1;
		int actual = 0;

		actual = my_strcmpOrder(str1, str2);

		CuAssertIntEquals(tc, expected, actual);
	}

	void TestQ1_strcmpOrder_caseSame(CuTest *tc)
	{
		char str1[] = "Timeless Content";
		char str2[] = "Timeless Content";
		int expected = -1;
		int actual = 0;

		actual = my_strcmpOrder(str1, str2);

		CuAssertIntEquals(tc, expected, actual);
	}

	void TestQ1_strcmpOrder_caseSomewhatDiff(CuTest *tc)
	{
		char str1[] = "Timeless Content";
		char str2[] = "Timeless Contents";
		int expected = 0;
		int actual = 0;

		actual = my_strcmpOrder(str1, str2);

		CuAssertIntEquals(tc, expected, actual);
	}

	//my 2 new test cases
	void TestQ1_strcmpOrder_caseNew1(CuTest *tc)
	{
		char str1[] = "abcdeft";
		char str2[] = "abcdefg";
		int expected = 1;
		int actual = 0;

		actual = my_strcmpOrder(str1, str2);

		CuAssertIntEquals(tc, expected, actual);
	}

	void TestQ1_strcmpOrder_caseNew2(CuTest *tc)
	{
		char str1[] = "coo l";
		char str2[] = "coo l";
		int expected = -1;
		int actual = 0;

		actual = my_strcmpOrder(str1, str2);

		CuAssertIntEquals(tc, expected, actual);
	}








	
	void TestQ1_strcat_TwoStrings(CuTest *tc) 
	{
		char str_expected[] = "HelloWorld!";
		char str1[] = "Hello";
		char str2[] = "World!";
		char* str_actual = my_strcat(str1, str2);
		
		CuAssertStrEquals(tc, str_expected, str_actual);

		free(str_actual);
	}

	void TestQ1_strcat_FirstEmpty(CuTest *tc) 
	{
		char str_expected[] = "World!";
		char str1[] = "";
		char str2[] = "World!";
		char* str_actual = my_strcat(str1, str2);
		
		CuAssertStrEquals(tc, str_expected, str_actual);

		free(str_actual);
	}

	void TestQ1_strcat_SecondEmpty(CuTest *tc) 
	{
		char str_expected[] = "Hello";
		char str1[] = "Hello";
		char str2[] = "";
		char* str_actual = my_strcat(str1, str2);
		
		CuAssertStrEquals(tc, str_expected, str_actual);

		free(str_actual);
	}

	//my 2 new test cases
	void TestQ1_strcatNew1(CuTest *tc) 
	{
		char str_expected[] = "VRRaj";
		char str1[] = "VRRaj";
		char str2[] = "";
		char* str_actual = my_strcat(str1, str2);
		
		CuAssertStrEquals(tc, str_expected, str_actual);

		free(str_actual);
	}

	void TestQ1_strcatNew2(CuTest *tc) 
	{
		char str_expected[] = "VRRaj Patel";
		char str1[] = "VRRaj";
		char str2[] = " Patel";
		char* str_actual = my_strcat(str1, str2);
		
		CuAssertStrEquals(tc, str_expected, str_actual);

		free(str_actual);
	}


// This section is commented out because Q2 contains a buggy code to be debugged.

// Uncomment this section only after you are done with Q1.


//===========================================================
//=================Question 2================================  


//New Test Cases for Question 2:

	//swap
	void TestQ2_SwapC1(CuTest *tc){
		char *str1 = "lab 3 swap";
		swap(&str1, &str1);

		CuAssertStrEquals(tc, "lab 3 swap", str1);
	}

	void TestQ2_SwapC2(CuTest *tc){
		char *str1 = "lab 3 swap";
		char *str2 = "nahhhh";
		swap(&str1, &str2);

		CuAssertStrEquals(tc, "lab 3 swap", str2);
		CuAssertStrEquals(tc, "nahhhh", str1);
	}

	//delete
	void TestQ2_Delete1(CuTest *tc){
		int size = 1;
		char **word_list = (char **)malloc(sizeof(char *) * size);

		char* str = "lab 3 swap";
		word_list[0] = str;

		CuAssertTrue(tc, 1);
		delete_wordlist(word_list, size);
	}

	void TestQ2_Delete2(CuTest *tc){
		int size = 1;
		char **word_list = (char **)malloc(sizeof(char *) * size);

		char* str = "--------------------------------------------------------------";
		word_list[0] = str;

		CuAssertTrue(tc, 1);
		delete_wordlist(word_list, size);
	}

	//read words

	void TestQ2_Read1(CuTest *tc){
		int expected_n = 6;
		char *expected_words[] = {"milan", "hello", "programming", "apple", "zebra", "banana"};

		int actual_n;
		char **actual_words = read_words("wordlist.txt", &actual_n);

		CuAssertIntEquals(tc, expected_n, actual_n);
		int i;
		for(i = 0; i < expected_n; i++){
			CuAssertStrEquals(tc, expected_words[i], actual_words[i]);
		}

		delete_wordlist(actual_words, actual_n);
	}

	void TestQ2_Read2(CuTest *tc){
		char input[] = "testing.txt";
		int size;

		char **actualList = read_words(input, &size);
		char *expected[] = {"my", "name", "is","vraj"};
		int i;
		for( i=0;i<size;i++){
			CuAssertStrEquals(tc, expected[i], actualList[i]);
		}

		delete_wordlist(actualList, size);

	}

	

	//all the BUBBLE cases

	void TestQ2_readandSort1(CuTest *tc) {

		char inputFile[] =  "wordlist.txt";
		int size;
		//create list using the input file
		char **actualList = read_words(inputFile,&size);
		sort_words_Bubble(actualList,size);

		char *expectedList[]={"apple","banana","hello","milan","programming","zebra"};
		
		int i;
		for (i=0;i<size;i++)
			CuAssertStrEquals(tc, expectedList[i], actualList[i]);
		delete_wordlist(actualList, size);

	}

	void TestQ2_readandSortNew2Bub(CuTest *tc) {

		char inputFile[] =  "testing.txt";
		int size;
		//create list using the input file
		char **actualList = read_words(inputFile,&size);
		sort_words_Bubble(actualList,size);

		char *expectedList[]={"is", "my", "name", "vraj"};

		int i;
		for (i=0;i<size;i++)
			CuAssertStrEquals(tc, expectedList[i], actualList[i]);
		
		delete_wordlist(actualList, size);

	}
	void TestQ2_readandSortNew3Bub(CuTest *tc) {

		char inputFile[] =  "testing2.txt";
		int size;
		//create list using the input file
		char **actualList = read_words(inputFile,&size);
		sort_words_Bubble(actualList,size);

		char *expectedList[]={"okay", "this", "trash"};

		int i;
		for (i=0;i<size;i++)
			CuAssertStrEquals(tc, expectedList[i], actualList[i]);
		
		delete_wordlist(actualList, size);

	}


	//All the selection cases
   
	void TestQ2_readandSort2(CuTest *tc) {

		char inputFile[] =  "wordlist.txt";
		int size;
		//create list using the input file
		char **actualList = read_words(inputFile,&size);
		sort_words_Selection(actualList,size);

		char *expectedList[]={"apple","banana","hello","milan","programming","zebra"};

		

		int i;
		for (i=0;i<size;i++)
			CuAssertStrEquals(tc, expectedList[i], actualList[i]);
		
		delete_wordlist(actualList, size);

	}






	//new selection
	void TestQ2_readandSortNew2(CuTest *tc) {

		char inputFile[] =  "testing.txt";
		int size;
		//create list using the input file
		char **actualList = read_words(inputFile,&size);
		sort_words_Selection(actualList,size);

		char *expectedList[]={"is", "my", "name", "vraj"};

		int i;
		for (i=0;i<size;i++)
			CuAssertStrEquals(tc, expectedList[i], actualList[i]);
		
		delete_wordlist(actualList, size);

	}

	void TestQ2_readandSortNew3(CuTest *tc) {

		char inputFile[] =  "testing2.txt";
		int size;
		//create list using the input file
		char **actualList = read_words(inputFile,&size);
		sort_words_Selection(actualList,size);

		char *expectedList[]={"okay", "this", "trash"};

		int i;
		for (i=0;i<size;i++)
			CuAssertStrEquals(tc, expectedList[i], actualList[i]);
		
		delete_wordlist(actualList, size);

	}


 


	

//===========================================================
	CuSuite* Lab3GetSuite() {

		CuSuite* suite = CuSuiteNew();

		SUITE_ADD_TEST(suite, TestQ1_strlen_case1); 
		SUITE_ADD_TEST(suite, TestQ1_strlen_case2);
		SUITE_ADD_TEST(suite, TestQ1_strlen_case0);
		//2 new test cases
		SUITE_ADD_TEST(suite, TestQ1_strlen_caseNew1);
		SUITE_ADD_TEST(suite, TestQ1_strlen_caseNew2);

		SUITE_ADD_TEST(suite, TestQ1_strcmp_caseEqual);
		SUITE_ADD_TEST(suite, TestQ1_strcmp_caseUnequalLength); 
		SUITE_ADD_TEST(suite, TestQ1_strcmp_caseUnequalContents);
		SUITE_ADD_TEST(suite, TestQ1_strcmp_caseEmpty);
		//2 new test cases
		SUITE_ADD_TEST(suite, TestQ1_strcmp_caseNew1);
		SUITE_ADD_TEST(suite, TestQ1_strcmp_caseNew2);

		SUITE_ADD_TEST(suite, TestQ1_strcmpOrder_caseSmaller);
		SUITE_ADD_TEST(suite, TestQ1_strcmpOrder_caseLarger); 
		SUITE_ADD_TEST(suite, TestQ1_strcmpOrder_caseSame);
		SUITE_ADD_TEST(suite, TestQ1_strcmpOrder_caseSomewhatDiff);
		//2 new test cases
		SUITE_ADD_TEST(suite, TestQ1_strcmpOrder_caseNew1);
		SUITE_ADD_TEST(suite, TestQ1_strcmpOrder_caseNew2);

		SUITE_ADD_TEST(suite, TestQ1_strcat_TwoStrings); 
		SUITE_ADD_TEST(suite, TestQ1_strcat_FirstEmpty);
		SUITE_ADD_TEST(suite, TestQ1_strcat_SecondEmpty);
		//2 new test cases
		SUITE_ADD_TEST(suite, TestQ1_strcatNew1);
		SUITE_ADD_TEST(suite, TestQ1_strcatNew2);

// Uncomment this section only after you are done with Q1.
// new test cases
	
		//swap
		SUITE_ADD_TEST(suite, TestQ2_SwapC1);
		SUITE_ADD_TEST(suite, TestQ2_SwapC2);
		//delete
		SUITE_ADD_TEST(suite, TestQ2_Delete1);
		SUITE_ADD_TEST(suite, TestQ2_Delete2);
		//read
		SUITE_ADD_TEST(suite, TestQ2_Read1);
		//SUITE_ADD_TEST(suite, TestQ2_Read2);
		
		//Bubble Sort
		SUITE_ADD_TEST(suite, TestQ2_readandSort1);
		//New
		//SUITE_ADD_TEST(suite, TestQ2_readandSortNew2Bub);
		//SUITE_ADD_TEST(suite, TestQ2_readandSortNew3Bub);

		//Selection Sort
		SUITE_ADD_TEST(suite, TestQ2_readandSort2);
		//new
		//SUITE_ADD_TEST(suite, TestQ2_readandSortNew2);
		//SUITE_ADD_TEST(suite, TestQ2_readandSortNew3);
		// SUITE_ADD_TEST(suite, TestQ2_readandSort222);
		//SUITE_ADD_TEST(suite, TestQ2_ReadWords_Case1);
        
       

		return suite;
	}
    
