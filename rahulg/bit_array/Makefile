//This is the makefile of bit_array project
  
final: main.o b_array.o
        gcc main.o b_array.o -o final
main.o: main.c b_array.h
        gcc -c main.c
b_array.o: b_array.c b_array.h
        gcc -c b_array.c
clean:
        rm *.o final
