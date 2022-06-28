CC = g++
TARGET = main
CXXFLAGS = -Wall -O0 -g
OBJECTS = cpu.o main.o state.o
main: $(OBJECTS)
	$(CC) $(CXXFLAGS) $(OBJECTS) -o $(TARGET) 
cpu.o: cpu.h state.h cpu.cpp
	$(CC) $(CXXFLAGS) -c cpu.cpp
state.o: state.cpp state.h
	$(CC) $(CXXFLAGS) -c state.cpp
main.o: cpu.h state.h main.cpp
	$(CC) $(CXXFLAGS) -c main.cpp

clean:
	rm -f $(OBJECTS) $(TARGET)