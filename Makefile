# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g


# SDL2 configuration
SDL_CFLAGS := $(shell sdl2-config --cflags)
SDL_LIBS := $(shell sdl2-config --libs)

# Targets
TARGET = Falling_Sand
# SRC = main.c gravity_engine.c
SRC = src/main.c \
			src/gravity_engine/gravity_engine.c \
			src/input/mouse_handler.c \

# Object files (same structure as source but in build dir)
OBJ = $(patsubst src/%.c,build/%.o,$(SRC))

# Default target
all: $(TARGET)

# Build target
$(TARGET): $(OBJ)
	@mkdir -p $(@D)  # Ensure build directory exists
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET) $(SDL_LIBS)

# Compile source files with directory structure
build/%.o: src/%.c
	@mkdir -p $(@D)  # Create output directory if needed
	$(CC) $(CFLAGS) $(INCLUDES) $(SDL_CFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -rf build

# Run the program
run: $(TARGET)
	./$(TARGET)

# Phony targets
.PHONY: all clean run
