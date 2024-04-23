# MakeFile for lab 3

# Compiler
CC = gcc

# TODO: Fill in the flags for:
# 	optimization level 0
# 	debugger
# 	turn all optional warnings
# 	turn all warnings into errors
# 	set standard c to c99
CFLAGS = -O0 -g -Wall -Wextra -Werror -std=c99

# default target; prerequisite: lab3
# note: target does not execute anything
all: lab3
	# Don't change this line!
	@echo "Good Luck in x13!"

# creates lab3.s file from lab3.c
lab3.s: lab3.c
	# creates .s file from lab3.c
	# renames the output lab3.s
	$(CC) $(CFLAGS) -S lab3.c -o lab3.s

# creates lab3_helper.s file from lab3_helper.c and lab3_helper.h
lab3_helper.s: lab3_helper.c lab3_helper.h
	# TODO: create lab3_helper.s from lab3_helper.c
	# TODO: make sure to name the output lab3_helper.s
	$(CC) $(CLFLAGS) -S lab3_helper.c -o lab3_helper.s

# creates lab3_helper.o file from lab3_helper.s
lab3_helper.o: lab3_helper.s
	# TODO: Fill in the name of the assembly file
	# TODO: Rename the output file to a .o file!
	$(CC) $(CFLAGS) -c lab3_helper.s -o lab3_helper.o

# creates lab3.o file from lab3.s
lab3.o: lab3.s
	# TODO: Fill in the missing flags & names!
	$(CC) $(CFLAGS) -c lab3.s -o lab3.o

# creates lab3 executable from lab3.o and lab3_helper.o
lab3_final: lab3.o lab3_helper.o
	# creates an executable file that links lab3.o and lab3_helper.o
	# renames the output to lab3.o
	# TODO: Tell the compiler which .o files to link.
	$(CC) $(CFLAGS) -o lab3 lab3.o lab3_helper.o

# Concise compilation rule
# Creates a lab3 executable file that depends on lab3.c lab3_helper.c and
# lab3_helper.h
lab3: lab3.c lab3_helper.c lab3_helper.h
	# creates an executable file named lab3 from lab3.c and lab3_helper.c files
	# TODO: Tell the compiler which .c files to compile.
	$(CC) $(CFLAGS) -o lab3 lab3.c lab3_helper.c

# fill in the .PHONY statement!
.PHONY: clean
clean:
	# TODO: Tell the compiler to remove all .o files and all executables that
	# start with lab3!
	# HINT: Maybe try looking through the PowerPoint
	rm -f lab3 *.o
