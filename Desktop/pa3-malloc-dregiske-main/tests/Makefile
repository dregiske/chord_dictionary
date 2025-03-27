# Compiler
CC = gcc
# Compiler flags
CFLAGS = -I.. -g -Wall -std=gnu99 -Xlinker -rpath=.. 
# Linker flags
LDFLAGS = -L.. -lvm

# List of source files (replace with your actual source files)
SRCS = $(wildcard *.c)
# List of executable targets
EXECS = $(SRCS:.c=)

# Default target to build all executables
all: $(EXECS)

# Rule to build each executable
%: %.c
	$(CC) $(CFLAGS) $< -o test_$@ $(LDFLAGS)

# Clean rule to remove generated executables
clean:
	rm -f test_*

# Phony targets
.PHONY: all clean