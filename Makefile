SRC_DIR = src
BUILD_DIR = build/debug
CC = g++
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_NAME = Main
INCLUDE_PATHS = -Iinclude
LIBRARY_PATHS = -Llib
COMPILER_FLAGS = -std=c++20 -Wall -O0 -g
LINKER_FLAGS = -lsdl2
FRAMEWORK = -F/Library/Frameworks -framework SDL2

all:
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(FRAMEWORK) $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME)