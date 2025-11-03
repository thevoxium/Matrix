CXX := g++-15
CXXFLAGS := -std=c++17 -O3 -fopenmp -Wall -I./math -I./vector
SRC := $(wildcard *.cpp src/math/*.cpp)
OBJ := $(SRC:.cpp=.o)
TARGET := main

all: $(TARGET)
	@echo "Running program:"
	@./$(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
