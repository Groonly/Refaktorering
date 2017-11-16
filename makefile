all:calculator

calculator: main2.o
	gcc -o calculator main2.o

main2.o:
	gcc -c main2.c
clean:
	rm \*.o
	rm \*.exe
run:
	calculator.exe
