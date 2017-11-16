all: calculator_test calculator

calculator_test: unity.o calculatorFunc.o calculatorTest.o
	gcc -o calculator_test calculatorFunc.o unity.o calculatorTest.o

calculator: calculatorFunc.c calculatorIO.c
	gcc -o calculator calculatorFunc.c calculatorIO.c

calculatorTest.o:
	gcc -c calculatorTest.c

calculatorFunc.o:
	gcc -c calculatorFunc.c

unity.o:
		gcc -c Libs/unity/src/unity.c

calculatorIO.o:
	gcc - c calculatorIO.c

clean:
	-rm -f *.o
	-rm -f *.exe

run:
	calculator.exe
test:
	calculator_test.exe
