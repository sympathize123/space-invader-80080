#include <fstream> // open, read, write file, stream
#include <iostream> // standard input output stream
#include <cstdio> // c input output stream
#include "opcode.h"
#include <sstream> // stringstream
// #include "opcode.h"
// #define SIZE_OF_TEMP_ARR 256
using namespace std;

int
main(int argc, const char *argv[])
{
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " Name" << endl;
        return 0;
    }
    ifstream read_file;
    read_file.open(argv[1]);
    if (!read_file.is_open())
    {
        cout << "can't open the file!!" << endl;
        return 0;
    }
    std::stringstream strStream;
    strStream << read_file.rdbuf(); //read the file
    std::string str = strStream.str(); //str holds the content of the file
    read_file.close();
    int pc = 0;
    for (int i = 0; i < str.length(); i++)
        pc += make_opcode(str, pc);
}