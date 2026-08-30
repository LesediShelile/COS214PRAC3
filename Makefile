CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

SRCS = $(wildcard *.cpp)
SRCS := $(filter-out main.cpp, $(SRCS))
OBJS = $(SRCS:.cpp=.o)

TARGET = gameverse
TEST_TARGET = gameverse_test

.PHONY: all clean run

all: $(TARGET)

$(TARGET): main.o $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.o $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f *.o $(TARGET) $(TEST_TARGET)
