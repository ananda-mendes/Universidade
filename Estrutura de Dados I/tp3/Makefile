all:  huffman.o cadastro.o hash.o main.o 
	gcc -o main huffman.o cadastro.o hash.o main.c 

huffman.o: huffman.c
	gcc -o huffman.o -c huffman.c

cadastro.o: cadastro.c
	gcc -o cadastro.o -c cadastro.c

hash.o: hash.c
	gcc -o hash.o -c hash.c
	
clean: 
	rm -f *.o main
run:
	./main < input.txt > output.txt
