all: alimento.o morador.o republica.o tarefa.o main.c
	gcc -o main main.c morador.o alimento.o republica.o tarefa.o -lm

alimento.o: alimento.c
	gcc -o alimento.o -c alimento.c

morador.o: morador.c
	gcc -o morador.o -c morador.c

republica.o: republica.c
	gcc -o republica.o -c republica.c

tarefa.o: tarefa.c
	gcc -o tarefa.o -c tarefa.c

clean:
	rm -f *.o main

run:
	./main 
