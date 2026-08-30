CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -g

TARGET = eventflow
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
