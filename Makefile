# Makefile for SDL2 Window Program

# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

# SDL2 configuration
SDL_CFLAGS := $(shell sdl2-config --cflags)
SDL_LIBS := $(shell sdl2-config --libs)

# Targets
TARGET = sdl_window
SRC = main.c
OBJ = $(SRC:.c=.o)

# Default target
all: $(TARGET)

# Build target
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET) $(SDL_LIBS)

# Compile source files
%.o: %.c
	$(CC) $(CFLAGS) $(SDL_CFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJ) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Phony targets
.PHONY: all clean run
