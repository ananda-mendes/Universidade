all: pilha.o quadrado.o losango.o trapezio.o times.o fila.o main.c
	gcc -o main main.c pilha.o quadrado.o losango.o trapezio.o times.o fila.o -lm -Wall

pilha.o: pilha.c
	gcc -o pilha.o -c pilha.c
	
quadrado.o: quadrado.c
	gcc -o quadrado.o -c quadrado.c
	
losango.o: losango.c
	gcc -o losango.o -c losango.c

trapezio.o: trapezio.c
	gcc -o trapezio.o -c trapezio.c

times.o: times.c
	gcc -o times.o -c times.c
	
fila.o: fila.c
	gcc -o fila.o -c fila.c


clean:
	rm -f *.o main

run:
	./main < input.txt > output.txt
