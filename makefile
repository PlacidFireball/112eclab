# Written by Jared Weiss with help from:
# gnu.org/software/make/manual/make.html

# The compiler
CC = gcc
# Flags for the compiler
CFLAGS = -Wall

# The name of the project
PROJ_NAME = eclab
# DEPENDANCIES
DEPS = eclab.h
# SOURCE FILES
SRCS = main.c read.c machines.c
# OBJECT FILES
# - for each word in SRCS replace .c with .o
OBJS = $(SRCS:.c=.o)

# Upon successful compilation, notify the user
all: $(PROJ_NAME)
	@echo Compiled project!

# Executable -> changes based on object files
$(PROJ_NAME): $(OBJS)
	$(CC) -o $(PROJ_NAME) $(OBJS)

# generic recipe for compiling c files
# makes a .o file based on a .c file
.c.o:
	$(CC) $(CFLAGS) $(DEPS) -c $<

.PHONY: clean
clean:
	rm -f *.o *~ *.gch $(PROJ_NAME)

# end makefile
