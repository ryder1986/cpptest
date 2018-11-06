#include <iostream>
#include "tool.h"
#include "test.h"
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
#if 0
    Test *test=new Test();
    PAUSE_HERE_3s
    delete test;
#else
    Test test;
#endif
    PAUSE_HERE
    return 0;
}

