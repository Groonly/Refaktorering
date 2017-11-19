all:calculator

calculator: source.o calculatorFunc.o userIO.o
	gcc source.o calculatorFunc.o userIO.o -o calculator

source.o:source.c
	gcc -c source.c

calculatorFunc.o:calculatorFunc.c
	gcc -c calculatorFunc.c

userIO.o:userIO.c
	gcc -c userIO.c

clean:
	rm \*.o
	rm \*.exe

run:
	calculator.exe
