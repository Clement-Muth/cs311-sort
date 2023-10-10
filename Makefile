CC = g++	# use g++ for compiling c++ code
CFLAGS = -g -Wall -std=c++11		# compilation flags: -g for debugging. Change to -O or -O2 for optimized code.

all: test1 test2 
SRCS = sorting_basic.cpp sorting_hybrid.cpp test_1.cpp test_2.cpp print_array.cpp
DEPS = $(SRCS:.cpp=.d)

.cpp.o:
	$(CC) -c $(CFLAGS) $< -o $@

test1: test1.o sorting_basic.o print_array.o
	$(CC) test1.o sorting_basic.o print_array.o -o test1

test2: test2.o sorting_hybrid.o sorting_basic.o print_array.o
	$(CC) test2.o sorting_hybrid.o sorting_basic.o print_array.o -o test2

clean:
	rm *.o test1 test2
