#ifndef TEST_H
#define TEST_H



/*
        reference:
            http://www.runoob.com/cplusplus/cpp-tutorial.html
            https://zh.cppreference.com
            http://www.cnblogs.com/haippy/p/3235560.html
            http://www.cplusplus.com/reference

        ? Folly是Facebook在2012年开源的一个C++11组件库。
*/

/*
    C++ keywords: static
    Usage
    declarations of namespace members with static storage duration and internal linkage
    definitions of block scope variables with static storage duration and initialized once
    declarations of class members not bound to specific instances
    Notes:
    1.dependent exsit
    2.last whole program
*/


/*
    basic concepts:
    Key Words:
        asm	else	new	this
        auto(util c++11??)	enum	operator	throw
        bool	explicit	private	true
        break	export	protected	try
        case	extern	public	typedef
        catch	false	register	typeid
        char	float	reinterpret_cast	typename
        class	for	return	union
        const(1)	friend	short	unsigned
        const_cast	goto	signed	using
        continue	if	sizeof	virtual
        default	inline	static	void
        delete	int	static_cast	volatile
        do	long	struct	wchar_t
        double	mutable	switch	while
        dynamic_cast	namespace	template

        (1):const（常量的，constant）所修饰的对象或变量不能被改变，
            修饰函数时，该函数不能改变在该函数外面声明的变量也不能调用任何非const函数。在函数的声明与定义时都要加上const，放在函数参数列表的最后一个括号后。
            在 C++ 中，用 const 声明一个变量，意味着该变量就是一个带类型的常量，可以代替 #define，且比 #define 多一个类型信息，且它执行内链接，可放在头文件中声明.
            但在 C 中，其声明则必须放在源文件（即 .C 文件）中，在 C 中 const 声明一个变量，除了不能改变其值外，它仍是一具变量
            note:
                1),in cpp, const just like #define , with variable check.
                2),what about static class ,const class ???
*/


#include <mutex>
#include <thread>
#include "tool.h"
class TestThread
{
public:
    static  int testconst;
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
        tmp=NULL;
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
                prt(info,"%c", tmp[0]);
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
    mutex lock;
    //   function fc;
};

class Test1
{
public:
    Test1()
    {
        // TestThread::testconst=1;
        prt(info,")))))))))))))))))))))-> %d",TestThread::testconst);

    }
    ~Test1()
    {
        //  prt(info,"deleteing  test1");
        //    this_thread::sleep_for(chrono::milliseconds(100000));
        prt(info,"delete    test1 done");
    }

private:

};


template <class T>
class RefHolder
{
    T& ref_;
public:
    RefHolder(T& ref) : ref_(ref) {}
    operator T& () const
    {
        return ref_;
    }
};

template <class T>
inline RefHolder<T> ByRef(T& t)
{
    return RefHolder<T>(t);
}
class TestEx
{
public:
    int x;
    explicit  TestEx(int tt)
    {
        x=tt;
        prt(info,"int %d",tt);


        float f = 100.555;
       // explicit int ttt= static_cast<int>(f) ;
    }
    ~TestEx(){}

  explicit  operator const char* () const
     {
        return "hello world";
      }

    //    void operator =(char c)
    //    {
    //        prt(info,"get %c",c);
    //    }
         void operator =(TestEx c)
         {
            prt(info,"a");
           // prt(info,"get %c",c);
        }
    //    void operator =(TestEx &c)
    //    {
    //        prt(info,"b");  // prt(info,"get %c",c);
    //    }
};
class TestQuit
{
public:
    int abc;
    TestQuit()
    {
          prt(info,"test quit start");
    }
//    TestQuit(TestQuit&&)
//    {

//    }
//    TestQuit && operator =(TestQuit &t)
//    {
//                return t;
//    }

    ~TestQuit()
    {
        prt(info,"quit");
    }
    TestQuit(TestQuit&& f) {}
    TestQuit& operator=(TestQuit&& f) {
        return *this;
    }
private:
};
class Test
{
public:
    Test();
    ~Test()
    {
        //   PAUSE_HERE_3s
        //        t1=NULL;
        //        prt(info,"tst now %p",&tst);
        //        prt(info,"t1 addr %p",t1);
        prt(info,"delete    test done");

        //        prt(info,"test quit, CLASS Test over");
    }
    void delete_obj(void *addr)
    {        prt(info,"after wait 3 s");


             prt(info,"tst now %p",&tst);
                  prt(info,"t1 addr %p",t1);
                       prt(info,"real addr %p",addr);
                            delete addr;
    }
    void fun1(TestQuit &&tq)
    {
       prt(info,"fun1");
    }
    void fun2(TestQuit tq)
    {
       prt(info,"fun1");
    }

private:
    Test1 *t1;
    int tst;
    // TestThread tt;
};
class Father{
public:

    Father()
    {
        a=5;
        prt(info,"construct father");
    }
    ~Father()
    {
   prt(info,"destuct father");
    }
    virtual  void fun()
    {
        prt(info,"  father fun");

    }
private:
public:
    int a;
};
class Child:public Father{
public:
    int b;
    Child()
    {
         // a = 6;
      // Father * f= (Father *)this;

        prt(info,"construct Child %d",a);
      //    a = 6;
    }
    ~Child()
    {
        prt(info,"destuct child");
    }
    virtual  void fun();
};
class TestMove{
public:
    TestMove()
    {
        t=new char[10];
        prt(info,"test move begin");
    }
    ~TestMove()
    {
        //if(t)
        delete t;
        prt(info,"test move end %p ",this);
    }

    TestMove(TestMove &tt)
    {
        prt(info,"t old addr %p",tt.t);

        t=tt.t;
        prt(info,"t addr %p",t);
        t=new char[10];

        prt(info,"copy %p ",this);

    }
    TestMove(TestMove &&tt)
    {
        t=tt.t;

        prt(info,"copy right %p ",this);

    }
    TestMove& operator =(TestMove tt)
    {
        prt(info,"=  %p ",this);
        return tt;

    }
    TestMove operator =(TestMove &&tt)
    {
        prt(info,"= right %p ",this);

        return tt;
    }

    char *t;

};

class Test101{
public:
    Test101()
    {
        test=99;
        prt(info,"Test101 constr (%p)",this);
        buf=new char(10);
    }
    ~Test101()
    {
        delete buf;
        prt(info,"Test101 destru (%p)",this);
    }
    Test101(Test101 &t)
    {
        prt(info,"copy (%p)",this);
    }
     //Test101(Test101 &&t)=default;
    Test101(Test101 &&t)
    {
         prt(info,"right copy(%p)",this);
         buf=t.buf;
    }
    void fun()
    {
         prt(info,"Test101 fun");
         buf[2]=3;
    }
    int test;
    char *buf;
};
class TestConstClass{
public:
    TestConstClass()
    {

    }
    ~TestConstClass()
    {

    }
  const  void fun_a() const
    {
        prt(info,"fun a ");
     int bb= fun_b();
     bb=3;
    }
    const  int fun_b() const
    {
        prt(info,"fun a ");
        return b;
    }
    static void fun_c()
    {
        for(int i=0;i<10;i++){
            prt(info,"in static fun");
        }
    }

    int a;
    int b;
};

#endif // TEST_H
