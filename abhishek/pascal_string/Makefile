P_string_output: p_string.o Driver.o
	gcc p_string.o Driver.o -o P_string_output
p_string.o: p_string.c 
	gcc -c p_string.c
Driver.o: Driver.c 
	gcc -c Driver.c 
clean:
	rm -rf *.o P_string_output
	