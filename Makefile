# Makefile for project 1
#
# You should not need to modify this file. 

CC		= gcc

CFLAGS		= -g  -Wall

CLIBS		= -lm 

all: problem1 problem2 problem3 

problem1: problem1.c p1.o p1.h
	$(CC) $(CFLAGS) -o problem1 problem1.c p1.o

problem2: problem2.c p2.o p2.h
	$(CC) $(CFLAGS) -o problem2 problem2.c p2.o

problem3: problem3.c p3.o p3.h
	$(CC) $(CFLAGS) -o problem3 problem3.c p3.o $(CLIBS) 

p1.o: p1.c p1.h
	$(CC) $(CFLAGS) -c p1.c
p2.o: p2.c p2.h
	$(CC) $(CFLAGS) -c p2.c
p3.o: p3.c p3.h
	$(CC) $(CFLAGS) -c p3.c 


clean:		
	rm -f *~ *.o a.out core problem1 problem2 problem3 p*.o  

run_problem1: 
	./problem1 
	
run_problem2: 
	./problem2 

run_problem3:
	./problem3


test_problem1:
	valgrind ./problem1
	
test_problem2: 
	valgrind ./problem2 

test_problem3:
	valgrind ./problem3


