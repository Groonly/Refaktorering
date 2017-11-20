OBJS = source.o calculatorFunc.o userIO.o
UNITY = unity.o
CC = gcc
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

calculator: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o calculator

calculator_test: $(OBJS) $(UNITY)
	gcc test.o $(OBJS) $(UNITY) -o calculator_test

source.o:source.c
	$(CC) $(CFLAGS) source.c

calculatorFunc.o:calculatorFunc.c calculatorFunc.h
	$(CC) $(CFLAGS) calculatorFunc.c

userIO.o:userIO.c userIO.h
	$(CC) $(CFLAGS) userIO.c

unity.o: Libs/unity/src/unity.c Libs/unity/src/unity.h
	$(CC) $(CFLAGS) $(UNITY)

test.o: test.c test.h
	$(CC) $(CFLAGS) test.c

clean:
	rm \*.o
	rm \*.exe

run:
	calculator.exe
test:
	calculator_test.exe
