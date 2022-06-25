CC = g++
TARGET = main.exe
OBJECTS = main.o
main.o: main.cpp 
	$(CC) -c main.cpp
main: main.o
	$(CC) $(OBJECTS) -o $(TARGET)
clean:
	rm *o