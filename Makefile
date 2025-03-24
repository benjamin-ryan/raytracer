# Compiler and Flags
CXX = g++
CXXFLAGS_COMMON = -Wall -Wextra -std=c++17
CXXFLAGS_DEBUG = $(CXXFLAGS_COMMON) -g
CXXFLAGS_RELEASE = $(CXXFLAGS_COMMON) -O2 -DNDEBUG

# Source and Targets
SRC = main.cpp
TARGET_DEBUG = raytracer_debug
TARGET_RELEASE = raytracer

# Phony Targets
.PHONY: all debug release test clean

# Default Target
all: release

debug: $(TARGET_DEBUG)

release: $(TARGET_RELEASE)

test: debug
	./$(TARGET_DEBUG)

$(TARGET_DEBUG): $(SRC)
	$(CXX) $(CXXFLAGS_DEBUG) -o $@ $^

$(TARGET_RELEASE): $(SRC)
	$(CXX) $(CXXFLAGS_RELEASE) -o $@ $^

clean:
	rm -f $(TARGET_DEBUG) $(TARGET_RELEASE)
	rm -rf $(TARGET_DEBUG).dSYM
