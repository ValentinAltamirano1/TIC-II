# La variable CC indica el ejecutable para el compilador C (usualmente son gcc o clang)
CC=gcc
# La variable CFLAGS indica las banderas para el compilador C
CFLAGS=-Wall -Wextra -std=gnu99 -ggdb
# La variable LDLIBS indica las banderas para la parte del "loader", usualmente librerías "-lxxxx"

# Este sería el ejecutable, sus dependencias son los .o
anagramas-hash: anagramas-hash.o anagramas-hash-func.o wrappers.o hash.o fgetword-normalizada.o

# Acá van los .o, make sabe que cada .o depende del .c correspondiente, acá se agrega la dependencia al .h
anagramas-hash-func.o: wrappers.h wrappers.o

