CC = g++
TARGET = main
CXXFLAGS = -Wall
OBJECTS = register.o
conditional_code.o: conditional_code.cpp
	$(CC) $(CXXFLAGS) -c conditional_code.cpp
register.o: register.cpp, conditional_code.o
	$(CC) $(CXXFLAGS)-c register.cpp
main: register.o main.cpp
	$(CC) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)
clean:
	rm $(OBJECTS) $(TARGET)