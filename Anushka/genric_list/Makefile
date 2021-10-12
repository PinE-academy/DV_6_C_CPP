demo: main.o glist.o giter.o
  gcc main.o glist.o giter.o-o <genric_list>
  Main.o: main.c glist.h giter.h
    gcc-c main.c
    glist.o: glist.c glist.h giter.h
      gcc-c glist.c
      giter.o: giter.o glist.h giter.h
        gcc-c giter.o
        clean:
          rm -rf*.o <genric_list>
