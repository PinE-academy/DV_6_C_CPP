wcomp:main.o strict.o  pattern.o fuzzy.o
  gcc main.o strict.o pattern.o fuzzy.o  -o wcomp
main.o:main.c strict.h pattern.h fuzzy.h
  gcc -c main.c
strict.o:strict.c strict.h
  gcc -c strict.c
pattern.o:pattern.c pattern.h
  gcc -c pattern.c
fuzzy.o:fuzzy.c fuzzy.h
  gcc -c fuzzy.c
