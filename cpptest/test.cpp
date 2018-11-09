#include "test.h"

//const int testconst=1;
Test::Test()
{


  //  TestEx e(12);
   TestEx e(12);
    //   e='f';

    TestEx f=e;
    f=e;
    prt(info,"---------------> %d",f.x);

    //  TestThread tt;
//    t1=NULL;
//     t1=new Test1();
//      DELETE_POINTER_LATER(Test1 *,t1,5000);
  //     prt(info,"t1 addr %p",t1);
 //   Timer2 t2;

    //t2.AsyncWait(3000,bind(&Test::delete_obj,this,placeholders::_1),t1);

    //  PAUSE_HERE_3s
}

//  int TestThread::testconst=17;
 int TestThread::testconst=18;
