#include <iostream>
#include "CString.h"
#include "process.h"

using namespace std;


int main(int argc, char *argv[])
{

    if (argc <= 1) {
        cout << "Insufficient number of arguments (min 1)" << endl;
        return 1;
    }

    cout << "Command Line :";
    for (int i = 0; i < argc; i++) {
      cout << " " << argv[i];
    }
    cout << endl;

    cout << "Maximum number of characters to be stored : " << MAX << endl;
    for (int i = 1; i < argc; i++) {
        process(argv[i]);
    }

    return 0;
}


