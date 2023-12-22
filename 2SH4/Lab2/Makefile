CC=gcc
CFLAGS=-I. -lm -g
DEPS = *.h
OBJ = AllTests.o testCases.o CuTest.o Question1.o Question2.o Question3.o Question4.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) 

Lab2: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

#testCompile: AllTests.c testCases.c CuTest.c Question1.c
#	gcc -o testLab0 AllTests.c testCases.c CuTest.c Question1.c

test:	testLab2
testLab2:
# next line must start with a real TAB (ASCII 9)
	./run.sh

.PHONY: clean

clean:
	$(RM) *.o 
