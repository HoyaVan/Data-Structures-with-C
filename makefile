# Compiler to use
CC = gcc
# Compiler flags
CFLAGS = -Wall -Wextra -g
# Target executable name
TARGET = stack
# Source files
SRCS = stack.c assignment1.c
# Object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)
# Rule to build the target
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)
	@rm -f $(OBJS)
# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)
# Phony targets to prevent conflicts with file names
remove: all clean
