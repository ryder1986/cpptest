#include <iostream>
#include <vector>
#include "tool.h"
#include "test.h"
//https://blog.csdn.net/u011529563/article/details/77620681
//https://www.cnblogs.com/concurrency/p/4066304.html
using namespace std;
void fun1(int a,int b=2,int c=3)
{
    prt(info,"%d %d %d",a,b,c);
}

void test1()
{
    Test *test=new Test();
    TestQuit tq;
    TestQuit &&ss=move(tq);
    tq.abc=1;
 //   test->fun1(move(tq));
    //Timer2 t2;
    //t2.AsyncWait(0,bind(&Test::fun1,test,placeholders::_1),ss);
    //t2.AsyncWait(0,bind(&Test::fun1,test,placeholders::_1),(tq));
    //test->fun1(move(tq));
    auto f=bind(&Test::fun1,test,placeholders::_1);
     f(move(tq));
  //  test->fun1(move(ss));
   // thread([=](){f(move(tq));}).detach();

    // test->fun2((tq));
    prt(info,"abc %d",tq.abc);
}
void test_vec()
{
    vector <int > ss;
    ss.push_back(1);
    ss.push_back(2);
    ss.push_back(3);
      prt(info,"sz  %d",ss.size());
    ss.erase(ss.begin());
 prt(info,"sz  %d",ss.size());
    prt(info,"begin %d",*ss.begin());
}
#if 1
int main()
{
    //fun1(1,5);

    cout << "start!" << endl;
    Child c;
    c.fun();

//     test_vec();
//    char *buf;
//    char *ss="1234";
//    char *pp;
//    memcpy(buf,ss,4);

//    test1();
#if 0
    Test *test=new Test();
    PAUSE_HERE_3s
    delete test;
#else
//    vector <int> ccc;
//   // ccc.reserve(10);
//    ccc.resize(10);
//    Test *test=new Test();
//    TestQuit tq;
//    tq.abc=1;
//    test->fun1(move(tq));
//    prt(info,"abc %d",tq.abc);
    //  prt(info,"test add r %p",test);
    //  delete test;
   // DELETE_POINTER_LATER(Test *,test,1000);
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

#else

class Point
{
    int x, y;
    public:
        Point(int a, int b) { x=a; y=b;}
        void MovePoint( int a, int b){ x+=a; y+=b;}
        void print(){ cout<<"x="<<endl;}


};

int main()
{
     Point point1( 10,10);
     point1.MovePoint(2,2);
     point1.print( );
     return 1;
}
#endif
