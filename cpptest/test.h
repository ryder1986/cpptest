#ifndef TEST_H
#define TEST_H
#include <mutex>
#include <thread>
#include "tool.h"
class TestThread
{
public:
    TestThread():t1(bind(&TestThread::fun,this)),mem1(18),
        f1(bind(&TestThread::fun,this))
    {
        tmp=new char[10];
        for(int i=0;i<10;i++)
        {
            tmp[i]='a'+i;
        }
        //  t1.start(1000);
      //  function<void(void)> ttt= bind(&TestThread::fun,this);
        auto ttt= bind(&TestThread::fun,this);
//thread1([f1,this](){});
       // thread1[&TestThread::f1,this](){};
     //   thread([ttt,this](){}).;
        thread([ttt,this](){ttt();}).detach();

    }
    ~TestThread()
    {
      //  aa.join();
        delete tmp;
        prt(info,"Bye %s",typeid(TestThread).name());
    }

    void fun()
    {
        // prt(info,"%s",demangle(typeid(TestThread).name()));
        try{
        while(1){
            prt(info,"%s", (typeid(TestThread).name()));
            this_thread::sleep_for(chrono::milliseconds(1000));
            //  prt(info,"\n");
            //throw exception();
            mem1++;
            prt(info,"%d", mem1);
         //   prt(info,"%c", tmp[0]);
          }
        }catch(exception e){
               prt(info,"thread done");
        }
    }
private:
    Timer1 t1;
    int mem1;
    char *tmp;
    function<void(void)> f1;
    thread thread1;
 //   function fc;
};

class Test
{
public:
    Test();
private:
   // TestThread tt;
};

#endif // TEST_H
