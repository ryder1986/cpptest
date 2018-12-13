/*
        reference:
            http://www.runoob.com/cplusplus/cpp-tutorial.html
            https://zh.cppreference.com
            http://www.cnblogs.com/haippy/p/3235560.html
            http://www.cplusplus.com/reference
            https://www.cnblogs.com/chengjundu/p/8288774.html

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
            修饰函数时，该函数不能改变在该函数外面声明的变量也不能调用任何非const函数。在函数的声明与定义时都要(*)加上const，放在函数参数列表的最后一个括号后。
            在 C++ 中，用 const 声明一个变量，意味着该变量就是一个带类型的常量，可以代替 #define，且比 #define 多一个类型信息，且它执行内链接，可放在头文件中声明.
            但在 C 中，其声明则必须放在源文件（即 .C 文件
            note:
                1),in cpp, const just like #define , with variable check.
                2),what about static class ,const class , what happen when derive???
        (2):explicit （显式的）的作用是"禁止单参数构造函数"被用于自动转换construct
            note:
                1),forbid using = when defination
                2),what happen when derive?
                总结： explicit关键字只需用于类内的单参数构造函数前面。由于无参数的构造函数和多参数的构造函数总是显示调用，这种情况在构造函数前加explicit无意义。
                google的c++规范中提到explicit的优点是可以避免不合时宜的类型变换，缺点无。所以google约定所有单参数的构造函数都必须是显示的，
                只有极少数情况下拷贝构造函数可以不声明称explicit。例如作为其他类的透明包装器的类。
                effective c++中说：被声明为explicit的构造函数通常比其non-explicit兄弟更受欢迎。
                因为它们禁止编译器执行非预期（往往也不被期望）的类型转换。除非我有一个好理由允许构造函数被用于隐式类型转换，否则我会把它声明为explicit，鼓励大家遵循相同的政策。
                mutable

        (3),mutable（易变的）是 C++ 中一个不常用的关键字。只能用于类的非静态和非常量数据成员。
                由于一个对象的状态由该对象的非静态数据成员决定，所以随着数据成员的改变，对像的状态也会随之发生变化。
                如果一个类的成员函数被声明为 const 类型，表示该函数不会改变对象的状态，也就是该函数不会修改类的非静态数据成员。
                但是有些时候需要在该类函数中对类的数据成员进行赋值，这个时候就需要用到 mutable 关键字。

*/

/*
        lambda:  []()->return type{}
        []：默认不捕获任何变量；
        [=]：默认以值捕获所有变量；
        [&]：默认以引用捕获所有变量；
        [x]：仅以值捕获x，其它变量不捕获；
        [&x]：仅以引用捕获x，其它变量不捕获；
        [=, &x]：默认以值捕获所有变量，但是x是例外，通过引用捕获；
        [&, x]：默认以引用捕获所有变量，但是x是例外，通过值捕获；
        [this]：通过引用捕获当前对象（其实是复制指针）；
        [*this]：通过传值方式捕获当前对象
/*
    Design paterns
    sington:
        1.Only one instance in a program
    observer:
    factory:
        1.It is just a switch
    iterator:
    note:
        1.the F**k patern design is about how to generate/design class!
        If you dont belive it useful ,dont give it a shit!
*/

/*
    Boost
*/

/
*
 memory leak:
    1.
    2.
    3
 segment fault:
    1.
    2.
    3
*/
/*
左值和右值都是针对表达式而言的，左值是指表达式结束后依然存在的持久对象，右值是指表达式结束时就不再存在的临时对象
https://www.cnblogs.com/davygeek/p/4219058.html
    move:
    forward:

*/
/*
    c++11: lock (https://blog.csdn.net/u013507368/article/details/45094959/)

*/


/
*
	template:
		https://www.cnblogs.com/yyxt/category/772515.html
*
/
