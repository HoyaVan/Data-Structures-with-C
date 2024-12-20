# Compiler to use
CC = gcc
# Compiler flags
CFLAGS = -Wall -Wextra -g
# Target executable name
TARGET = stack
# Source files
SRCS = stack.c assignment1.c assignment2.c
# Object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Rule to build the target
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)
	rm -f $(OBJS) # Automatically remove object files after creating the executable

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
