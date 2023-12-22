#include <assert.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CuTest.h"
#include "Questions.h"
    

    
    
//=========Question 1==================================
void TestQ1_add(CuTest *tc) {

	int n = 5;
	double input1[5] = {3.60, 4.78, 6.00, 10.00, 0.01};
	double input2[5] = {1.50, 2.00, 3.30, 9.90, 1.00};
	double actual[5];
	double expected [5] = {5.10, 6.78, 9.30, 19.90, 1.01};
	add_vectors(input1,input2,actual,n);
	int i;
	for (i=0; i<n; i++)
		CuAssertDblEquals(tc, expected[i], actual[i],0.009);
}

//TestCase1
void TestQ1_addCase1(CuTest *tc) {

	int n = 5;
	double input1[5] = {3.00, 4.00, 6.00, 10.00, 0.00};
	double input2[5] = {1.00, 2.00, 3.00, 9.00, 1.00};
	double actual[5];
	double expected [5] = {4.00, 6.00, 9.00, 19.00, 1.00};
	add_vectors(input1,input2,actual,n);
	int i;
	for (i=0; i<n; i++)
		CuAssertDblEquals(tc, expected[i], actual[i],0.009);
}

//TestCase2
void TestQ1_addCase2(CuTest *tc) {

	int n = 5;
	double input1[5] = {3.61, 4.78, 6.01, 10.00, 0.01};
	double input2[5] = {1.50, 2.01, 3.30, 9.91, 1.01};
	double actual[5];
	double expected [5] = {5.11, 6.79, 9.31, 19.91, 1.02};
	add_vectors(input1,input2,actual,n);
	int i;
	for (i=0; i<n; i++)
		CuAssertDblEquals(tc, expected[i], actual[i],0.009);
}

//TestCase3
void TestQ1_addCase3(CuTest *tc) {

	int n = 5;
	double input1[5] = {0.00, 4.78, 6.00, -10.00, 6.01};
	double input2[5] = {1.50, -2.00, 5.30, 9.90, -1.00};
	double actual[5];
	double expected [5] = {1.50, 2.78, 11.30, -0.10, 5.01};
	add_vectors(input1,input2,actual,n);
	int i;
	for (i=0; i<n; i++)
		CuAssertDblEquals(tc, expected[i], actual[i],0.009);
}
    
void TestQ1_scalar_prod(CuTest *tc) {

	int n = 5;
	double input1[5] = {3.60, 4.78, 6.00, 10.00, 0.01};
	double input2[5] = {1.50, 2.00, 3.30, 9.90, 1.00};
	double expected=133.770 ;
	double actual = scalar_prod(input1,input2,n);

	CuAssertDblEquals(tc, expected, actual,0.009);
}

//Test Case 1
void TestQ1_scalar_prodCase1(CuTest *tc) {

	int n = 5;
	double input1[5] = {3.00, 4.00, 6.00, 10.00, 0.00};
	double input2[5] = {1.00, 2.00, 3.00, 9.00, 1.00};
	double expected=119.00;
	double actual = scalar_prod(input1,input2,n);

	CuAssertDblEquals(tc, expected, actual,0.009);
}

//Test Case 2
void TestQ1_scalar_prodCase2(CuTest *tc) {

	int n = 5;
	double input1[5] = {-3.60, 4.78, 6.00, -10.00, -0.01};
	double input2[5] = {1.50, -2.00, -3.30, -9.90, 1.00};
	double expected= 64.23 ;
	double actual = scalar_prod(input1,input2,n);

	CuAssertDblEquals(tc, expected, actual,0.009);
}

//Test Case 3
void TestQ1_scalar_prodCase3(CuTest *tc) {

	int n = 5;
	double input1[5] = {0.00, 4.78, 6.00, 0.00, 0.01};
	double input2[5] = {1.50, 0.00, 3.30, 9.90, 0.00};
	double expected= 19.80;
	double actual = scalar_prod(input1,input2,n);

	CuAssertDblEquals(tc, expected, actual,0.009);
}

void TestQ1_norm(CuTest *tc) {

	int n = 5;
	double input1[5] = {3.60, 4.78, 6.00, 10.00, 0.01};
	double expected=13.108 ;
    double actual = norm2(input1,n);

    CuAssertDblEquals(tc, expected, actual,0.009);
}

//Test Case 1
void TestQ1_normCase1(CuTest *tc) {

	int n = 5;
	double input1[5] = {3.00, 4.00, 6.00, 10.00, 0.00};
	double expected=12.6886 ;
    double actual = norm2(input1,n);

    CuAssertDblEquals(tc, expected, actual,0.009);
}

//Test Case 2
void TestQ1_normCase2(CuTest *tc) {

	int n = 5;
	double input1[5] = { 0.00, 0.00,  0.00, 0.00,  0.00};
	double expected= 0.00 ;
    double actual = norm2(input1,n);

    CuAssertDblEquals(tc, expected, actual,0.009);
}

//Test Case 3
void TestQ1_normCase3(CuTest *tc) {

	int n = 5;
	double input1[5] = {-3.60, 4.78, -6.00, 0.00, 0.01};
	double expected=8.474 ;
    double actual = norm2(input1,n);

    CuAssertDblEquals(tc, expected, actual,0.009);
}

//===========================================================
//=================Question 2================================  

void TestQ2(CuTest *tc) {
	int n = 3;
	int input[3][3] = {{1, 2, 3},{ 5, 8, 9},{ 0, 3, 5}};
	int expected[9]= {1, 2, 5, 3, 8, 0, 9, 3, 5};
	int actual[9];
	diag_scan(input,actual);

	int i;
	for (i=0; i<n*n; i++)
		CuAssertIntEquals(tc, expected[i], actual[i]);
}

//Test Case#1
void TestQ2Case1(CuTest *tc) {
	int n = 3;
	int input[3][3] = {{10, 9, 8},{ 7, 6, 5},{ 4, 3, 2}};
	int expected[9]= {10, 9, 7, 8, 6, 4, 5, 3, 2};
	int actual[9];
	diag_scan(input,actual);

	int i;
	for (i=0; i<n*n; i++)
		CuAssertIntEquals(tc, expected[i], actual[i]);
}



//Test Case #2
void TestQ2Case2(CuTest *tc) {
	int n = 3;
	int input[3][3] = {{1, 34, 3},{ 5, 38, 99},{ 50, 3, 5}};
	int expected[9]= {1, 34, 5, 3, 38, 50, 99, 3, 5};
	int actual[9];
	diag_scan(input,actual);

	int i;
	for (i=0; i<n*n; i++)
		CuAssertIntEquals(tc, expected[i], actual[i]);
}

//Test Case #3
void TestQ2Case3(CuTest *tc) {
	int n = 3;
	int input[3][3] = {{11, 2, 53},{ 5, 8, 1},{ 34, 3, 5}};
	int expected[9]= {11, 2, 5, 53, 8, 34, 1, 3, 5};
	int actual[9];
	diag_scan(input,actual);

	int i;
	for (i=0; i<n*n; i++)
		CuAssertIntEquals(tc, expected[i], actual[i]);
}
    

//===========================================================
//=================Question 3================================   
void TestQ3_1(CuTest *tc) {
	int n=8;
	int input[]={0,0,23,0,-7,0,0,48};
	struct Q3Struct actual[8] = {0};
	struct Q3Struct expected[8] = {{23, 2}, {-7, 4}, {48, 7}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}};
	efficient(input,actual,n);
    
	int i;
	for (i=0; i<n; i++){
		CuAssertIntEquals(tc, expected[i].val, actual[i].val);
		CuAssertIntEquals(tc, expected[i].pos, actual[i].pos);
	}
}

//Test Case #1
void TestQ3_1Case1(CuTest *tc) {
	int n=8;
	int input[]={0,0,21,0,-4,0,0,8};
	struct Q3Struct actual[8] = {0};
	struct Q3Struct expected[8] = {{21, 2}, {-4, 4}, {8, 7}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}};
	efficient(input,actual,n);
    
	int i;
	for (i=0; i<n; i++){
		CuAssertIntEquals(tc, expected[i].val, actual[i].val);
		CuAssertIntEquals(tc, expected[i].pos, actual[i].pos);
	}
}

//Test Case #2
void TestQ3_1Case2(CuTest *tc) {
	int n=8;
	int input[]={0,2,0,0,-7,0,0,48};
	struct Q3Struct actual[8] = {0};
	struct Q3Struct expected[8] = {{2, 1}, {-7, 4}, {48, 7}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}};
	efficient(input,actual,n);
    
	int i;
	for (i=0; i<n; i++){
		CuAssertIntEquals(tc, expected[i].val, actual[i].val);
		CuAssertIntEquals(tc, expected[i].pos, actual[i].pos);
	}
}
//Test Case #3
void TestQ3_1Case3(CuTest *tc) {
	int n=8;
	int input[]={0,0,0,0,7,0,6,4};
	struct Q3Struct actual[8] = {0};
	struct Q3Struct expected[8] = {{7, 4}, {6,6}, {4, 7}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}};
	efficient(input,actual,n);
    
	int i;
	for (i=0; i<n; i++){
		CuAssertIntEquals(tc, expected[i].val, actual[i].val);
		CuAssertIntEquals(tc, expected[i].pos, actual[i].pos);
	}
}

void TestQ3_zeros(CuTest *tc) {
	int n=8;
	int input[]={0,0,0,0,0,0,0,0};
	struct Q3Struct actual[8] = {0};
	struct Q3Struct expected[8] = {0};
	efficient(input,actual,n);
    
	int i;
	for (i=0; i<n; i++){
		CuAssertIntEquals(tc, expected[i].val, actual[i].val);
		CuAssertIntEquals(tc, expected[i].pos, actual[i].pos);
	}
}

void TestQ3_combined(CuTest *tc) {
	int n=8;
	int input[]={0,0,23,0,-7,0,0,48};
	struct Q3Struct int_result[8] = {0};
	int expected[8] = {0,0,23,0,-7,0,0,48};
	int actual[8] = {0};
	efficient(input,int_result,n);
	reconstruct(actual, 8, int_result, 3);

	int i;
	for (i=0; i<n; i++){
		CuAssertIntEquals(tc, expected[i], actual[i]);
	}
}
    

//===========================================================
//=================Question 4================================   
void TestQ4_BubbleSort_1(CuTest *tc) 
{
	int n=6;
	struct Q4Struct input[]={{10, 'c'}, {2, 'B'}, {-5, 'k'}, {12, 'z'}, {77, 'a'}, {-42, '?'}};	
	struct Q4Struct expected[]={{-42, '?'}, {-5, 'k'}, {2, 'B'}, {10, 'c'}, {12, 'z'}, {77, 'a'}};		
	
	sortDatabyBubble(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}

void TestQ4_BubbleSort_2(CuTest *tc) 
{
	int n=8;
	struct Q4Struct input[]={{-23, '='}, {78, ' '}, {11, 'Y'}, {-2, '0'}, {41, '+'}, {0, 'm'}, {55, 'T'}, {-9, 'o'}};	
	struct Q4Struct expected[]={{-23, '='}, {-9, 'o'}, {-2, '0'}, {0, 'm'}, {11, 'Y'}, {41, '+'}, {55, 'T'}, {78, ' '}};		
	
	sortDatabyBubble(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}

//Test Case #1
void TestQ4_BubbleSort_Case1(CuTest *tc) 
{
	int n=8;
	struct Q4Struct input[]={{-22, '='}, {78, ' '}, {8, 'Y'}, {-2, '0'}, {22, '+'}, {0, 'm'}, {50, 'T'}, {-4, 'o'}};	
	struct Q4Struct expected[]={{-22, '='}, {-4, 'o'}, {-2, '0'}, {0, 'm'}, {8, 'Y'}, {22, '+'}, {50, 'T'}, {78, ' '}};		
	
	sortDatabyBubble(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}


void TestQ4_SelectionSort_1(CuTest *tc) 
{
	int n=6;
	struct Q4Struct input[]={{10, 'c'}, {2, 'B'}, {-5, 'k'}, {12, 'z'}, {77, 'a'}, {-42, '?'}};	
	struct Q4Struct expected[]={{-42, '?'}, {-5, 'k'}, {2, 'B'}, {10, 'c'}, {12, 'z'}, {77, 'a'}};		
	
	sortDatabySelection(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}

void TestQ4_SelectionSort_2(CuTest *tc) 
{
	int n=8;
	struct Q4Struct input[]={{-23, '='}, {78, ' '}, {11, 'Y'}, {-2, '0'}, {41, '+'}, {0, 'm'}, {55, 'T'}, {-9, 'o'}};	
	struct Q4Struct expected[]={{-23, '='}, {-9, 'o'}, {-2, '0'}, {0, 'm'}, {11, 'Y'}, {41, '+'}, {55, 'T'}, {78, ' '}};			
	
	sortDatabySelection(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}

//Test Case #2
void TestQ4_SelectionSort_Case2(CuTest *tc) 
{
	int n=8;
	struct Q4Struct input[]={{-22, '='}, {78, ' '}, {8, 'Y'}, {-2, '0'}, {22, '+'}, {0, 'm'}, {50, 'T'}, {-4, 'o'}};	
	struct Q4Struct expected[]={{-22, '='}, {-4, 'o'}, {-2, '0'}, {0, 'm'}, {8, 'Y'}, {22, '+'}, {50, 'T'}, {78, ' '}};				
	
	sortDatabySelection(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}

//Test Case #3
void TestQ4_SelectionSort_Test3(CuTest *tc) 
{
	int n=5;
	struct Q4Struct input[]={ {78, ' '},  {-2, '0'}, {22, '+'}, {0, 'm'}, {-4, 'o'}};	
	struct Q4Struct expected[]={ {-4, 'o'}, {-2, '0'}, {0, 'm'},  {22, '+'}, {78, ' '}};				
	
	sortDatabySelection(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}






CuSuite* Lab2GetSuite() {

	CuSuite* suite = CuSuiteNew();

	SUITE_ADD_TEST(suite, TestQ1_add);
	//Test Cases for Add
	SUITE_ADD_TEST(suite, TestQ1_addCase1);
	SUITE_ADD_TEST(suite, TestQ1_addCase2);
	SUITE_ADD_TEST(suite, TestQ1_addCase3);
	SUITE_ADD_TEST(suite, TestQ1_scalar_prod);
	//Test Cases for ScalProd
	SUITE_ADD_TEST(suite, TestQ1_scalar_prodCase1);
	SUITE_ADD_TEST(suite, TestQ1_scalar_prodCase2);
	SUITE_ADD_TEST(suite, TestQ1_scalar_prodCase3);
	SUITE_ADD_TEST(suite, TestQ1_norm);
	//Test Cases for norm
	SUITE_ADD_TEST(suite, TestQ1_normCase1);
	SUITE_ADD_TEST(suite, TestQ1_normCase2);
	SUITE_ADD_TEST(suite, TestQ1_normCase3);


	SUITE_ADD_TEST(suite, TestQ2);
	//New Test Cases
	SUITE_ADD_TEST(suite, TestQ2Case1);
	SUITE_ADD_TEST(suite, TestQ2Case2);
	SUITE_ADD_TEST(suite, TestQ2Case3);

	SUITE_ADD_TEST(suite, TestQ3_1);
	//New Test Cases
	SUITE_ADD_TEST(suite, TestQ3_1Case1);
	SUITE_ADD_TEST(suite, TestQ3_1Case2);
	SUITE_ADD_TEST(suite, TestQ3_1Case3);
	//The rest are not mine
	SUITE_ADD_TEST(suite, TestQ3_zeros);
	SUITE_ADD_TEST(suite, TestQ3_combined);

	SUITE_ADD_TEST(suite, TestQ4_BubbleSort_1);
	SUITE_ADD_TEST(suite, TestQ4_BubbleSort_2);
	//New Test Cases
	SUITE_ADD_TEST(suite, TestQ4_BubbleSort_Case1);
	//these 2 aren't mine
	SUITE_ADD_TEST(suite, TestQ4_SelectionSort_1);
	SUITE_ADD_TEST(suite, TestQ4_SelectionSort_2);
	//New Test Cases
	SUITE_ADD_TEST(suite, TestQ4_SelectionSort_Case2);
	SUITE_ADD_TEST(suite, TestQ4_SelectionSort_Test3);


	return suite;
}
    
