all:calculator

calculator: source.o calculatorFunc.o
	gcc -o calculator source.o calculatorFunc.o

source.o:
	gcc -c source.c

calculatorFunc.o:
	gcc -c calculatorFunc.c

clean:
	rm \*.o
	rm \*.exe
run:
	calculator.exe
