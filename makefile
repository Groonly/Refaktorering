all:calculator calculator_test

calculator: source.o calculatorFunc.o userIO.o
	gcc source.o calculatorFunc.o userIO.o -o calculator

calculator_test: test.o unity.o calculatorFunc.o
	gcc test.o unity.o calculatorFunc.o -o calculator_test

source.o:source.c
	gcc -c source.c

calculatorFunc.o:calculatorFunc.c
	gcc -c calculatorFunc.c

userIO.o:userIO.c
	gcc -c userIO.c

unity.o:
	gcc -c Libs/unity/src/unity.c

test.o:
	gcc -c test.c

clean:
	rm \*.o
	rm \*.exe

run:
	calculator.exe
test:
	calculator_test.exe
