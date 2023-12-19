    #include <stdio.h>
    #include "CuTest.h"
    
    CuSuite* Lab1GetSuite();
    
    void RunAllTests(void) {
        CuString *output = CuStringNew();
        CuSuite* suite = CuSuiteNew();        
        
        CuSuiteAddSuite(suite, Lab1GetSuite());
        CuSuiteRun(suite);
        CuSuiteSummary(suite, output);
        CuSuiteDetails(suite, output);
        printf("%s\n", output->buffer);

        CuStringDelete(output);
        CuSuiteDelete(suite);        
    }
    
    int main(void) {
        RunAllTests();
    }
