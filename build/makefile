# Compiler
CXX = g++

# Directories
SRC_DIR = ../src
BUILD_DIR = .

# Source files
SRC = $(SRC_DIR)/main.cpp

# Output executable
TARGET = $(BUILD_DIR)/app

# Compiler flags
CXXFLAGS = -Wall -Wextra -O2

# Build target
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Clean target
clean:
	rm -f $(TARGET)
