all:calculator

calculator: main.o
	gcc -o calculator main2.o

main2.o:
	gcc -c main.c
clean:
	rm \*.o
	rm \*.exe
run:
	calculator.exe
