#include <assert.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CuTest.h"
#include "Questions.h"
    

    
//=========Question 1==================================
    void TestQ1_for(CuTest *tc) {

        int actual = Q1_for(3);
        int expected = 166833;
        CuAssertIntEquals(tc, expected, actual);

        actual = Q1_for(11);
        expected = 45045;
        CuAssertIntEquals(tc, expected, actual);

        actual = Q1_for(37);
        expected = 13986;
        CuAssertIntEquals(tc, expected, actual);
    }
    void TestQ1_while(CuTest *tc) {

        int actual = Q1_while(3);
        int expected = 166833;
        CuAssertIntEquals(tc, expected, actual);

        actual = Q1_while(11);
        expected = 45045;
        CuAssertIntEquals(tc, expected, actual);

        actual = Q1_while(37);
        expected = 13986;
        CuAssertIntEquals(tc, expected, actual);

        //Test Case for While loop #1
        actual = Q1_while(999);
        expected = 999;
        CuAssertIntEquals(tc, expected, actual);

        //Test Case for While loop #2
        actual = Q1_while(4);
        expected = 124500;
        CuAssertIntEquals(tc, expected, actual);
    }
    void TestQ1_do(CuTest *tc) {

        int actual = Q1_dowhile(3);
        int expected = 166833;
        CuAssertIntEquals(tc, expected, actual);

        actual = Q1_dowhile(11);
        expected = 45045;
        CuAssertIntEquals(tc, expected, actual);

        actual = Q1_dowhile(37);
        expected = 13986;
        CuAssertIntEquals(tc, expected, actual);
    }
//===========================================================
//=================Question 2================================
    void TestQ2(CuTest *tc) {
        
        float threshold = 3.7;
	    float input = -10.1;
        int actual = Q2_FPN(input, threshold);
        int expected = -999;
        CuAssertIntEquals(tc, expected, actual);

        input = -6.2;
        actual = Q2_FPN(input, threshold);
        expected = 0;
        CuAssertIntEquals(tc, expected, actual);

        input = -2.4;
        actual = Q2_FPN(input, threshold);
        expected = 1;
        CuAssertIntEquals(tc, expected, actual);

        input = 1.8;
        actual = Q2_FPN(input, threshold);
        expected = 2;
        CuAssertIntEquals(tc, expected, actual);

        input = 4.9;
        actual = Q2_FPN(input, threshold);
        expected = 3;
        CuAssertIntEquals(tc, expected, actual);

        input = 91.1;
        actual = Q2_FPN(input, threshold);
        expected = -999;
        CuAssertIntEquals(tc, expected, actual);
    }   


//===========================================================
//=================Question 3================================   
    void TestQ3_none(CuTest *tc) {
        int input = 5;
        int expected[100]={0};
        int actual[100]={0};
        int expectedCount = 0;
        int actualCount = Q3(input,actual);
        CuAssertIntEquals(tc, expectedCount, actualCount);
	    
        int i;
        for (i=0;i<100;i++)
          	CuAssertIntEquals(tc, expected[i], actual[i]);
    }

    void TestQ3_10(CuTest *tc) {
        int input = 10;
        int expected[100]={0},actual[100]={0};
        expected[0]= 6;
        int expectedCount=1;
        int actualCount = Q3(input,actual);
        CuAssertIntEquals(tc, expectedCount, actualCount);
	    
        int i;
        for (i=0;i<100;i++)
          	CuAssertIntEquals(tc, expected[i], actual[i]);
    }

    //TEST CASE #1
    void TestQ3_6(CuTest *tc) {
        int input = 6;
        int expected[100]={0},actual[100]={0};
        expected[0]= 6;
        int expectedCount=1;
        int actualCount = Q3(input,actual);
        CuAssertIntEquals(tc, expectedCount, actualCount);
	    
        int i;
        for (i=0;i<100;i++)
          	CuAssertIntEquals(tc, expected[i], actual[i]);
    }

    //Test Case #2
    void TestQ3_30(CuTest *tc) {
        int input = 30;
        int expected[100]={0},actual[100]={0};
        expected[0]= 6;
        expected[1] = 28;
        int expectedCount=2;
        int actualCount = Q3(input,actual);
        CuAssertIntEquals(tc, expectedCount, actualCount);
	    
        int i;
        for (i=0;i<100;i++)
          	CuAssertIntEquals(tc, expected[i], actual[i]);
    }

    //Test Case #3
    void TestQ3_500(CuTest *tc) {
        int input = 500;
        int expected[100]={0},actual[100]={0};
        expected[0]= 6;
        expected[1]= 28;
        expected[2]= 496;
        int expectedCount=3;
        int actualCount = Q3(input,actual);
        CuAssertIntEquals(tc, expectedCount, actualCount);
	    
        int i;
        for (i=0;i<100;i++)
          	CuAssertIntEquals(tc, expected[i], actual[i]);
    }

    void TestQ3_1000(CuTest *tc) {
        int input = 1000;
        int expected[100]={0};
        int actual[100]={0};
        expected[0]=6;
        expected[1]=28;
        expected[2]=496;
        int expectedCount=3;
        int actualCount = Q3(input,actual);
        CuAssertIntEquals(tc, expectedCount, actualCount);
	
        int i;
        for (i=0;i<100;i++)
        	 CuAssertIntEquals(tc, expected[i], actual[i]);
    }
      
    void TestQ3_10000(CuTest *tc) {
        int input = 10000;
        int expected[100]={0},actual[100]={0};
        expected[0]=6;
        expected[1]=28;
        expected[2]=496;
        expected[3]=8128;
        int expectedCount=4;
        int actualCount = Q3(input,actual);
        CuAssertIntEquals(tc, expectedCount, actualCount);
    
    	int i;
        for (i=0;i<100;i++)
          	CuAssertIntEquals(tc, expected[i], actual[i]);

    }
    
    void TestQ3_neg(CuTest *tc) {
        int input = -1000;
        int expected[100]={0},actual[100]={0};
        int expectedCount=0;
        int actualCount = Q3(input,actual);
        CuAssertIntEquals(tc, expectedCount, actualCount);
	    
        int i;
        for (i=0;i<100;i++)
          	CuAssertIntEquals(tc, expected[i], actual[i]);
    }



//===========================================================
//=================Question 4================================ 
    void TestQ4_8(CuTest *tc) {

        int targetArray[8] = {6, 13, 0, -7, 28, 1, 45, -4};
		int inputSize = 8;
        int expectedArray[8] = {-7, -4, 0, 1, 6, 13, 28, 45};
        int expectedPass = 7;
        int actualPass = Q4_Bubble(targetArray, inputSize);        
        CuAssertIntEquals(tc, expectedPass, actualPass);

        int i;
        for (i = 0; i < inputSize; i++)
          	CuAssertIntEquals(tc, expectedArray[i], targetArray[i]);
    } 

    void TestQ4_16(CuTest *tc) {

		int targetArray[16] = {11, 3, -2, 88, 10, 25, 103, 91, -44, 0, 233, -85, 1015, -7, -411, -27};
		int inputSize = 16;
        int expectedArray[16] = {-411, -85, -44, -27, -7, -2, 0, 3, 10, 11, 25, 88, 91, 103, 233, 1015};
        int expectedPass = 15;
        int actualPass = Q4_Bubble(targetArray, inputSize);        
        CuAssertIntEquals(tc, expectedPass, actualPass);

        int i;
        for (i = 0; i < inputSize; i++)
          	CuAssertIntEquals(tc, expectedArray[i], targetArray[i]);
    } 

    //NEW TEST CASE
    void TestQ4_5(CuTest *tc) {

		int targetArray[5] = {1, 456, 7, -43, 5};
		int inputSize = 5;
        int expectedArray[5] = {-43, 1, 5, 7, 456};
        int expectedPass = 4;
        int actualPass = Q4_Bubble(targetArray, inputSize);        
        CuAssertIntEquals(tc, expectedPass, actualPass);

        int i;
        for (i = 0; i < inputSize; i++)
          	CuAssertIntEquals(tc, expectedArray[i], targetArray[i]);
    } 

    void TestQ4_25(CuTest *tc) {

		int targetArray[25] = {889, 12, 69, 7, -25, 25, 353, -1422, -1, -65535, 11, 89, 63, -375, 227, 55, 3688, -324, 71, -6, -31, 88, 477, -5225, -91};
		int inputSize = 25;
        int expectedArray[25] = {-65535, -5225, -1422, -375, -324, -91, -31, -25, -6, -1, 7, 11, 12, 25, 55, 63, 69, 71, 88, 89, 227, 353, 477, 889, 3688};

        // three possible passes, all valid.  We are not grading for efficiency optimization.
        int expectedPass1 = 23;
        int expectedPass2 = 24;
        int expectedPass3 = 25; 

        int actualPass = Q4_Bubble(targetArray, inputSize);        
        
        if(actualPass == expectedPass1)
            CuAssertIntEquals(tc, expectedPass1, actualPass);
        else if(actualPass == expectedPass2)
            CuAssertIntEquals(tc, expectedPass2, actualPass);
        else
            CuAssertIntEquals(tc, expectedPass3, actualPass);

        int i;
        for (i = 0; i < inputSize; i++)
            CuAssertIntEquals(tc, expectedArray[i], targetArray[i]);
    } 

  

    CuSuite* Lab1GetSuite() {
        
        CuSuite* suite = CuSuiteNew();

        
        SUITE_ADD_TEST(suite, TestQ1_for);
        SUITE_ADD_TEST(suite, TestQ1_while);
        SUITE_ADD_TEST(suite, TestQ1_do);
        

        SUITE_ADD_TEST(suite, TestQ2);

        
        SUITE_ADD_TEST(suite, TestQ3_none);
        SUITE_ADD_TEST(suite, TestQ3_10);
        SUITE_ADD_TEST(suite, TestQ3_1000);
        SUITE_ADD_TEST(suite, TestQ3_10000);
        SUITE_ADD_TEST(suite, TestQ3_neg);
        //New Test Cases
        SUITE_ADD_TEST(suite, TestQ3_6);
        SUITE_ADD_TEST(suite, TestQ3_30);
        SUITE_ADD_TEST(suite, TestQ3_500);

     
        

        SUITE_ADD_TEST(suite, TestQ4_8);
        SUITE_ADD_TEST(suite, TestQ4_16);
        SUITE_ADD_TEST(suite, TestQ4_5); // additional test cases
        SUITE_ADD_TEST(suite, TestQ4_25);


        return suite;
    }
    
