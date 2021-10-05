//*****Makefile for bit_array*****

bit_array: main.o b_array.o b_array.h
	gcc main.o b_array.o -o bit_array

main.o: main.c  b_array.h
	gcc -c main.c 

b_array.o: b_array.c b_array.h
	gcc -c b_array.c

clean: 
	rm *.o bit_array