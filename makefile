all:calculator

calculator: main.o calculatorFunc.o
	gcc -o calculator main.o calculatorFunc.o

main.o:
	gcc -c main.c

calculatorFunc.o:
	gcc -c calculatorFunc.c
	
clean:
	rm \*.o
	rm \*.exe
run:
	calculator.exe
