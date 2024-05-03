CC = gcc

CFLAGS = -Wall -g -Werror -Wextra -std=c99 -I./include

OBJ = my_alloc.o

all: ${OBJ}
test: ${OBJ} test.o my_alloc.o
	    $(CC) $(CFLAGS) -L./lib -lcriterion -o test test.o my_alloc.o
	    ./test
clean:
	    rm *.o .*.swp .*.swo

distclean: clean
	    rm test

.PHONY: all clean distclean test




#=======================
#CC = gcc
#CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99 -g -I./include -I./include/criterion
#OBJ = my_calc.o
#
#all: ${OBJ}
#
#test: ${OBJ} my_calc.o my_parser.o
#        $(CC) -L./lib -lcriterion -o test my_calc.o my_parser.o
#        timeout 1m ./test
#
#clean:
#        $(RM) *.o .*.swp .*.swo
#
#distclean: clean
#        $(RM) test
#
#.PHONY: all clean distclean test
