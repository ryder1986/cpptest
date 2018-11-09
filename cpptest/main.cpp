#include <iostream>
#include <vector>
#include "tool.h"
#include "test.h"
using namespace std;
void fun1(int a,int b=2,int c=3)
{
    prt(info,"%d %d %d",a,b,c);
}

int main()
{
    fun1(1,5);

    cout << "Hello World!" << endl;

#if 0
    Test *test=new Test();
    PAUSE_HERE_3s
    delete test;
#else
//    vector <int> ccc;
//   // ccc.reserve(10);
//    ccc.resize(10);
    Test *test=new Test();
    //  prt(info,"test add r %p",test);
    //  delete test;
    DELETE_POINTER_LATER(Test *,test,1000);
     //delete test;
      //prt(info,"sss %p ok",test)
   // test=(Test *)0x1;
   // delete test;
//    void *addr=test;
//    delete addr;
//      \
//  thread([addr](){\
//      this_thread::sleep_for(chrono::milliseconds(1000));\
//      delete (Test*)addr;prt(info,"delete %p ok",addr);\
//  }\
//  ).detach();\
//      \
//  addr=NULL;\



    prt(info,"ok pause");
#endif
    PAUSE_HERE
    return 0;
}

