OBJS = source.o calculatorFunc.o userIO.o
TEST = unity.o test.o calculatorFunc.o
CC = gcc
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: calculator calculator_test test
calculator: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o calculator
calculator_test: $(TEST)
	$(CC) $(LFLAGS) $(TEST) -o calculator_test

source.o:source.c
	$(CC) $(CFLAGS) source.c

calculatorFunc.o:calculatorFunc.c calculatorFunc.h
	$(CC) $(CFLAGS) calculatorFunc.c

userIO.o:userIO.c userIO.h
	$(CC) $(CFLAGS) userIO.c

unity.o: Libs/unity/src/unity.c Libs/unity/src/unity.h
	$(CC) $(CFLAGS) Libs/unity/src/unity.c

test.o: test.c
	$(CC) $(CFLAGS) test.c

clean:
	rm \*.o
	rm \*.exe

run:
	calculator.exe
test:
	calculator_test.exe
