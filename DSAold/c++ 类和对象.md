#### 类与对象

| 类型      | 变量 |
| --------- | ---- |
| int       | a    |
| long long | b    |
| char      | c    |
| double    | d    |
| float     | e    |

类型 = 类型数据 + 类型操作

| 类     | 对象     |
| ------ | -------- |
| Cat    | garfield |
| Dog    | odie     |
| People | hug      |

```c++
class Cat{
};
class Dog{
};
class People{
};
```

```c++
struct 在c++中是类 不是结构体
```

类 = 类数据 + 类操作



#### 成员属性与方法；

```c++
class People{
  string name;
  Day birthday;
  double height;
  double weight;
  void say(string word);
  void run(Location &loc);//&loc坐值引用
};
```

| pubilc            | 共有访问权限 |
| ----------------- | ------------ |
| private           | 私有访问权限 |
| protected【继承】 | 受保护的权限 |

友元：一个外部的类可以访问你的私有权限

属性为私有，方法为公有

getset值的合法性检查



#### 构造函数与析构函数

构造函数：在函数定义部分使用的函数

##### 构造函数的构造顺序是根据函数声明的顺序构造的，而不是根据参数列表的顺序

析构函数：在函数销毁操作使用的函数

void 不代表没有返回值，只是返回值没有意义

在People(string name)里面，才是真正的没有返回值

| 构造/析构函数                            | 使用方式            |
| ---------------------------------------- | ------------------- |
| 默认构造函数                             | People a;           |
| People (string name);【没用返回值】      | People a("hug");    |
| People(const People &a);【一定要有引用】 | 拷贝构造，与=不等价 |
| ～People();                              | 无                  |

如果是数组的话，开内存需要开在堆里，不会自动保存堆里的数据，内存需要动态的申请，需要用析构函数

如果是栈的话，开内存需要开在栈里，系统会保存之上的数据，内存不需要动态的申请，使用完毕后系统会自动回收

数组的堆内存需要析构函数回收

#### 类属性与类方法

例如：人类有多少个，放在人这个类里面的任何一个对象中都不合适，但是它属于类属性

如果人类灭绝了，那么这个类就应该不存在了，销毁这个类放在任何一个对象上去做都不合适，属于类方法；

```c++
class People{
public:
    void say(string word);
    void run(Location &loc);
    static void is_valid_height(double height);//类内部的静态声明是类方法；
private:
    static int total_num;//类内部的静态属性就是类属性；
    string __name;
    Day __birthday;
    double __height;
    double __weight;
}
```

如何区别类方法与成员方法呢

1.类方法前面有static

2.this指针是用来指向成员的，this里面存储的是指针，代表该指针指向某个使用成员方法的成员



#### const方法

```c++
class People{
public:
    void say(string word);
    void run(Location &loc);
    string &name() const;//【在这个方法的内部不去修改当前对象的所有属性值】
    static void is_valid_height(double height);//类内部的静态声明是类方法；
private:
    static int total_num;//类内部的静态属性就是类属性；
    string __name;
    Day __birthday;
    double __height;
    double __weight;
}
```





#### 对象与引用

SomeClass  a;

SomeClass. &b = a;  贴在对象上的另外一个标签

如果访问b 访问的还是a  如果改了b，那么a中的值也改了



#### C++中的结构体与类

struct 访问默认权限为public

class 访问默认权限为private

```c++
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostream;//std::c++标准库命名空间;

struct Point{
	Point(int x, int y) : x(x), y(y){};
	Point(const Point &a) : x(a.x), y(a.y){};
	int x, y;
};//两个整型；

/*
struct Test{
	Test(int x, int y) : p2(x, y), p1(p2){};
	Point p1;
	Point p2;
};//由于p1先声明的，所以先析构p1,就会报warning；
*/

struct Test{
	Test(int x, int y) : p1(x, y), p2(p1){
		Test::num++;//每增加一个Test，num就加一；
	}
	Test(const Test &a) : p1(a.p1), p2(a.p2){
		Test::num++;
	}//拷贝构造；
	
	Point p1;
	Point p2;
	static void count(){
		cout << "All Test Object : " << Test::num << endl;
		return ;
	}
private:
	static int num;//所有Test类型对象的个数；类属性；声明，需要在类外部初始化,static关键字只能在类声明的时候调用；
};//两个Point；

int Test::num = 0;//命名空间;

ostream & operator << (ostream &out, Point &a){
	out << "(" << a.x << "," << a.y << ")" << endl;
	return out;
}

Test func(){
	Test temp(5, 6);
	Test::count();
	return temp;
}

int main(){
	Test a(2, 3), b(1, 2);
	// cout << a.p1;
	Test::count();
	Test c = func();
	Test::count();
	cout << a.p2;
	cout << sizeof(Test) << " " << sizeof(Point) << endl;
	return 0;
}
//1.开辟对象数据区；2.匹配构造函数；3.完成最终的构造；相当于对数据区初始化，与成员无关，只与对象有关；
//所有对象公用一套地址类型，只要知道类型，就知道可以用哪种方法，不可以用哪种方法；
//**虚函数会影响类的大小，普通的成员函数跟着类走，虚函数是跟着对象走的；
```





#### 返回值优化（RVO）



#### 拷贝构造

1.与内存无关的 值复制

2.与内存有关的 (1)新开内存 (2)值给过去



#### 析构函数不能被重载