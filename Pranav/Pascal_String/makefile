Pascal_String_Out : Pascal_Strings.o Pascal_Driver.0
	gcc-11 Pascal_Strings.o Pascal_Driver.o -o Pascal_String_Out

Pascal_Strings.o : Pascal_Strings.c
	gcc-11 -c Pascal_Strings.c

Pascal_Driver.o : Pascal_Driver.c
	gcc-11 -c Pascal_Driver.c

clean :
	rm -rf *.o Pascal_String_Out