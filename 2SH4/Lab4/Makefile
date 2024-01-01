CC=g++
CFLAGS=-I. -lm -g
DEPS = *.h
OBJ = Test.o Matrix.o 

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Lab4: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

#testCompile: Test.cpp Matrix.cpp
#	g++ -o Test.cpp Matrix.cpp
test:	testLab4
testLab4:
# next line must start with a real TAB (ASCII 9)
	./run.sh

.PHONY: clean

clean:
	$(RM) *.o Lab4
