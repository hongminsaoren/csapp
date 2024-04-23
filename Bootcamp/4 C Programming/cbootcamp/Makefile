CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -std=gnu99

all: queue ref-queue passing_args pointer_arith mem_mgmt structs macros typedefs casting cstdlib

structs:
	$(CC) -o structs structs.c 

macros:
	$(CC) -o ./extras/macros ./extras/macros.c 

typedefs:
	$(CC) -o ./extras/typedefs ./extras/typedefs.c 

casting: ./extras/casting.c
	$(CC) $(CFLAGS) -o ./extras/casting ./extras/casting.c

passing_args: ./extras/passing_args.c
	$(CC) $(CFLAGS) -o ./extras/passing_args ./extras/passing_args.c 

pointer_arith: pointer_arith.c
	$(CC) $(CFLAGS) -o pointer_arith pointer_arith.c 
	
mem_mgmt: mem_mgmt.c
	$(CC) $(CFLAGS) -o mem_mgmt mem_mgmt.c 

queue: ./extras/main.c ./extras/student-queue.c
	$(CC) $(CFLAGS) -o ./extras/student_queue_test ./extras/student-queue.c ./extras/main.c

ref-queue: ./extras/main.c ./extras/ref-queue.c
	$(CC) $(CFLAGS) -o ./extras/ref_queue_test ./extras/ref-queue.c ./extras/main.c

cstdlib: atoi.c files.c getopt.c strcat.c strlen.c strcpy.c
	$(CC) $(CFLAGS) -o atoi atoi.c
	$(CC) $(CFLAGS) -o files files.c
	$(CC) $(CFLAGS) -o getopt getopt.c
	$(CC) $(CFLAGS) -o strcat strcat.c
	$(CC) $(CFLAGS) -o strlen strlen.c
	$(CC) $(CFLAGS) -o strcpy strcpy.c

clean:
	rm ./extras/student_queue_test ./extras/ref_queue_test ./extras/passing_args pointer_arith mem_mgmt structs ./extras/macros ./extras/typedefs ./extras/casting atoi files getopt strcat strlen strcpy
