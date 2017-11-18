all:calculator

calculator: source.o calculatorFunc.o
	gcc source.o calculatorFunc.o -o calculator

source.o:source.c
	gcc -c source.c

calculatorFunc.o:calculatorFunc.c
	gcc -c calculatorFunc.c

clean:
	rm \*.o
	rm \*.exe
	
run:
	calculator.exe
