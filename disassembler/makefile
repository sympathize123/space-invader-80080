CC = g++
TARGET = main
OBJECTS = disassembler_main.o opcode.o
opcode.o: opcode.cpp
	$(CC) -c opcode.cpp
disassembler_main.o: opcode.o
	$(CC) -c disassembler_main.cpp
main: disassembler_main.o
	$(CC) $(OBJECTS) -o $(TARGET)
clean:
	rm $(OBJECTS) $(TARGET)