#include "test.h"

Test::Test()
{
    //  TestThread tt;
    t1=NULL;
     t1=new Test1();
      DELETE_POINTER_LATER(Test1 *,t1,5000);
  //     prt(info,"t1 addr %p",t1);
 //   Timer2 t2;

    //t2.AsyncWait(3000,bind(&Test::delete_obj,this,placeholders::_1),t1);

    //  PAUSE_HERE_3s
}

