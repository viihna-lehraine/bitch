CXX = g++
CXXFLAGS = -std=c++17 -Wall

SRC = $(wildcard src/*.cpp src/modules/*.cpp)
BUILD_DIR = build
TARGET = $(BUILD_DIR)/bitch

all: $(TARGET)

$(TARGET): $(SRC)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf $(BUILD_DIR)

format:
	./scripts/clang_format.sh
