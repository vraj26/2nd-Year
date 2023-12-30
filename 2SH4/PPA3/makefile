CC=gcc
CFLAGS=-I. -g
OBJ = MacUILib.o myStringLib.o PPA3.o 
DEPS = *.h
#POSTLINKER = -lncurses   ## uncomment this if on Linux
EXEC = PPA3

%.o: %.c $(DEPENDS)
	$(CC) -c -o $@ $< $(CFLAGS)

${EXEC} : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) ${POSTLINKER}

clean :
	rm -r ${OBJ} ${EXEC} ${EXEC}.exe

