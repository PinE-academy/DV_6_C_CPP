#To run this file:Type "make" in current directory of this file in CLI.

Pascal_String: p_strings.o Driver.o 
	gcc p_strings.o Driver.o -o Pascal_String

p_strings.o: p_strings.c
	gcc -c p_strings.c

Driver.o: Driver.c
	gcc -c Driver.c

clean:
	rm -rf *.o
	rm -rf *.exe
