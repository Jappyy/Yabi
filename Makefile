CC = gcc
CFLAGS = -O3 -march=native -std=c11 -Wall -Wextra -Wpedantic -Wconversion -lncurses
BDIR = $(shell pwd)/bin
SDIR = $(shell pwd)/src
ODIR = $(shell pwd)/obj

OBJS = $(addprefix $(ODIR)/, args.o benchmark.o brackets.o compiler.o debug.o error.o files.o getch.o info.o interpreter.o IO.o optimizer.o parser.o tokens.o main.o)


all: $(OBJS) 
	@$(CC) $(OBJS) -o $(BDIR)/yabi $(CFLAGS)

$(ODIR)/%.o: $(SDIR)/%.c
	@mkdir -p $(ODIR)
	@$(CC) -c $(CFLAGS) -o $@ $^

.PHONY: clean

clean: 
	@rm -r $(ODIR)


