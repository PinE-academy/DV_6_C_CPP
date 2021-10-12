generic_list : main.o glist.o giter.o
	gcc -c generic_list main.o glist.o giter.o

main.o : main.c
	gcc -c main.c

glist.o : glist.c
	gcc -c glist.c

giter.o : giter.c
	gcc -c giter.c

clean :
	rm main.o
	rm glist.o
	rm giter.o
