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





template<typename T, int i = 1>
class CComputeSomething {
public:
    typedef volatile T *retType; // 类型计算
    enum {
        retValume = i + CComputeSomething<T, i - 1>::retValume
    }; // 数值计算，递归
    static void f() {
        std::cout << "CComputeSomething:i = " << i << " retValume = " << retValume << '\n';
    }
};

//递归结束特例
template<typename T>
class CComputeSomething<T, 0> {
public:
    enum {
        retValume = 0
    };
};
template <typename T>
class CComputingFunc {
public:
    static void f() { T::f(); }
};

int test_tem() {
    CComputeSomething<int>::retType a = 0;
    //这里的递归深度注意，不同编译器允许的最大深度不同,编译时添加 -ftemplate-depth=500来修改编译器允许的递归最大深度
    CComputingFunc<CComputeSomething<int, 500>>::f();
    return 0;
}

int test_move1(TestMove &md)
{
    prt(info,"func1 left start");
    md.t[1]='c';
    prt(info,"func1 left end");

    prt(info,"addr22 %p",&md);

}
int test_move1(TestMove &&md)
{
       prt(info,"addr321 %p",&md);
//    prt(info,"func1 right start");
//    md.t[1]='d';
//    prt(info,"func1 right end");
//  //  TestMove ff=move(md);
    prt(info,"addr %p",md.t);
  TestMove &&ff=move(md);
     prt(info,"addr321 %p",&md);
 // md.t=NULL;
  //    TestMove ppp=move(md);
//     // TestMove ttt=ff;

//    prt(info,"addr33 %p",&md);
//    prt(info,"afetr move %c",md.t[1]);

//    prt(info,"addr333 %p",&ff);

//    prt(info,"func 1end with %c",ff.t[1]);

}
int test_move()
{
    prt(info,"func start");
    TestMove t;
    prt(info,"addr1 %p",&t);
       prt(info,"addr %p",t.t);
    test_move1(t);
    prt(info,"addr2 %p",&t);

    test_move1(std::move(t));
    prt(info,"addr3 %p",&t);

      t.t[1]='e';
  //  prt(info,"func end with %c",t.t[1]);


}
Test101 get_test101()
{
        Test101 t101;
    return t101;
}
void get_test102()
{
     static  Test101 t101;
//    static Test101 t101;
  //  return t101;
}

extern Test101 t101;
void fun1()
{
    prt(info,"%p",&t101);
   // Test101 s=move(t101);
    Test101 s(move(t101));
    s.buf[1]=3;
     prt(info,"%d",s.test);
    prt(info,"%p",&s);
}
class Test123{
public:
    Test123()
    {
        prt(info,"c");
    }
    ~Test123()
    {
        prt(info,"d");
    }
    void print()
    {

    }
    Test123(Test123&)
    {
        prt(info,"cp ");
    }
//    void operator =(Test123&)
//    {
//        prt(info,"op");
//    }
    void operator =(Test123)
    {
        prt(info,"op");
    }
};

int main()
{
    Test123 t123;
    Test123 t456;
    t123=t456;
    Test123 tmp(t456);
//    int abc;
//        fun1();
//   cout << "start!" << endl;

//   prt(info,"%p",&t101);


//   prt(info,"%d",t101.test);

//       t101.fun();
   // Test101 t101=get_test101();
  //  prt(info," %p",&t101);

  //   get_test101();
 //  get_test102();
     //prt(info,"before tset move");
   //   TestMove t;
//    test_move();
  //  prt(info,"after tset move");

    //test_tem();
//    Child c;
//    c.fun();

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
