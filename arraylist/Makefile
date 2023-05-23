CFLAGS=-Wall -Wextra -std=gnu99 -O0 -ggdb -fsanitize=signed-integer-overflow -fsanitize=undefined
LDLIBS=-lubsan
arraylist: arraylist.o arraylist-func-esqueleto.o arraylist-profe.o wrappers.o
arraylist.o: wrappers.h arraylist.h
arraylist-func-esqueleto.o: wrappers.h arraylist.h
arraylist-profe.o: wrappers.h arraylist.h
wrappers.o: wrappers.h

