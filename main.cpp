#include <fstream>
#include "iostream"
#include <vector>
// #include "opcode.h"
#define SIZE_OF_TEMP_ARR 256
using namespace std;


int
main(int argc, const char *argv[])
{
    if (argc < 2)
        cerr << "Usage: " << argv[0] << "Name" << endl;
    ifstream read_file;
    read_file.open(argv[1]);
    if (!read_file.is_open())
    {
        cout << "can't open the file!!" << endl;
        while (!read_file.eof())
        {
            char temp_arr[SIZE_OF_TEMP_ARR];
            read_file.getline(temp_arr, 256);
            for(int i = 0;i < SIZE_OF_TEMP_ARR;i++)
                cout << temp_arr[i];
                // make_opcode(temp_arr[i]);
            cout << endl;
        }
    }
}