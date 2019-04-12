

#### &&优先级高于||

break是彻底结束整个单层循环【对于嵌套循环则跳出所在的层】

continue是结束本层循环—循环体中continue之后的语句不会被执行，这一轮循环结束，下一轮正常开始

goto是跳转到指定的某个语句—它会严重影响程序的结构，代码可读性和可维护性产生极大的破坏

#### 函数重载

两个以上的函数名，具有相同的函数名，但是形参的个数或者类型不同，编译器根据实参与形参的类型以及个数最佳匹配，自动确定要调用的函数，叫做函数重载



### 从c到c++

c的标准头文件29个【面向过程】

c++的标准头文件87个，比c多了58个，每个头文件中不带.h,前面加上一个c

多了异常处理【帮助debug】、类和对象、

STL【起源与惠普实验室】算法与数据结构完全分离 类型萃取 ITERATOR迭代器、

模版、Lamba。 

#### C++【面向过程编程 面向对象编程 面向泛型编程 函数式编程】

#### C    【				函数指针			宏			      】

printf与scanf对应了两个对象cin和cout

#### 特点：抽象 封装 继承 多态

#### 抽象：数据抽象 行为抽象

#### 封装：也就是类

#### 多态性：指同一段程序，可以直接处理多种类型对象的能力



#### 构造函数

函数名与类名完全相同

不能定义返回类型，也就是不能有return语句

可以有形参，也可以没有形参， 可以带有默认参数

可以重载

#### 复制构造函数

有构造函数所有的特性

它的形参是本类对象的引用，作用是用一个已经存在的对象(即为函数的参数)来初始化一个新的对象。复制构造函数使用的就是引用传参

复制函数对象的具体声明

```c++
class 类名{
    public:
    类名(类名&对象名){
        //实现；
    }
};
```

#### 初始化列表

 ```c++
构造函数(参数列表):成员变量(常数或者参数){
    //构造函数的函数体；
}
 ```

#### 析构函数

没有返回值也没有任何参数；

可以是虚函数；

与构造函数一样是一个类的公有成员

```c++
class clock{
    ~clock(){}//析构函数；  
};
```

#### 命名空间

```c++
namespace 命名空间名{
    命名空间内的各种声明(函数声明， 类声明等);
}
```

```c++
命名空间名::标识符名
```

```c++
namespace NS{
    class Class{
    //类成员
    }
}
NS::Class object;
```





#### 组合函数

如果这个类具有内嵌对象成员，那么各个内嵌对象将会首先被创建

我们既要对类中的基本数据初始化，也要对内嵌对象成员进行初始化

```c++
类名::类名(形参表)：内嵌对象1(形参表),内嵌对象2(形参表)...{
   //初始化函数体
}
```

Static  const  全局变量 new 默认值是0   在全局区



malloc 在栈中 不给初始化会随机值



#### 数组

```c++
数据类型 标识符[常量表达式1][常量表达式2]...;
```

```c++
vector<类型>数组对象名(长度);
vector<类型>数组对象名(数组长度,元素初值);
vector<int> v(10,1);//建立一个有10个元素的vector整型对象v，初值全设置为1
```



#### 函数模版

```c++
template<模板参数列表>
类型名 函数名(参数表)
{
    //函数定义
}
```



#### 类模版

```c++
template<模板参数表>
class 类名
{
    类成员声明
}
```

![屏幕快照 2018-09-16 下午3.48.14](/Users/hanxu/Desktop/屏幕快照/屏幕快照 2018-09-16 下午3.48.14.png)



#### 声明函数指针

```c++
返回值类型 (* 函数指针名)(形参表)
```



#### new

```c++
new 数据类型(初始化参数列表);
int *point;
point=new int(2);
int *point = new int;//没有初值
int *point = new int();//初始值为0
int *a=new int[n];
new(address) Object();//就地构造；
```

#### delete 所有用new分配的内存，必须要用delete删除，不然会内存泄漏

```c++
delete line;//对于基本类型或者对象的指针
delete[] a;//对于指向数组的指针

```

如果删除的是一个数组的话，必须加上[]



#### qsort

```c++
void qsort(s,n,sizeof(s[0]),&cmp);
```

第一个参数s是参与排序的数组名，或者开始排序的地址；

第二个参数是参与排序的个数；

第三个元素是每个元素的大小；

第四个参数是比较函数cmp指针；

```c++
int cmp(const void * a,const void * b);

int cmp(const void *a, const void *b)
{
     return(*(int *)a-*(int * )b);  //升序
     //return(*(int *)b-*(int * )a); //降序
}
```



#### lamada表达式

```c++
[捕获列表](参数列表)->返回值类型{函数体}
```

必须永远包括【捕获列表】和【函数体】，参数列表和返回值类型可以省略



#### Makefile的使用

```c++
目标文件 : 依赖文件1 依赖文件2 ...
    编译命令
```

```c++
Point.o: Point.cpp Point.h
    g++ -c Point.cpp
```

```c++
all: Point.o main
    ./main
Point.o: Point.cpp Point.h
    g++ -c Point.cpp

main: Point.o main.cpp
    g++ -o main Point.o main.cpp
```

```c++
clean:
    rm -f *.o *~ main
```



queue类：

头文件：queue

命名空间：std 用来实现命名空间的，将相同的工具放到不同的命名空间就没有冲突

【结构定义】声明：queue<data_type> q;

【结构操作】q.front( )查看队首元素

			q.empty( )队列盘空
	
			q.push( )入队	
	
			q.pop( )出队
	
			q.size( )队列元素数量

stack类：

头文件：stack

命名空间：std 用来实现命名空间的，将相同的工具放到不同的命名空间就没有冲突

【结构定义】声明：stack<data_type> s;

【结构操作】s.front( )查看队首元素

			s.empty( )队列盘空
	
			s.push( )入队	
	
			s.pop( )出队
	
			s.size( )队列元素数量

string类：

头文件：string

命名空间：std

【结构定义】声明：string s1、s2；

【结构操作】s1 == s2 字符串判等		strcpy

			s1 < s2  字典序小于		strcmp
	
			s1 > s2  字典序大于
	
			s1 += s2  字符串连接
	
			s.length()字符串长度【O(1)】		strlen【每次调用都要重新扫描一次O(n)】

#### 非标准：

map的底层是红黑树 红黑树log(n)

用map的红黑树而不用hash的原因  红黑树是二叉排序树可以用中序遍历而按照顺序输出建值hash表的扩容很麻烦

Hash_map类：字符串 O(1)

头文件：<hash_map>/<ext/hash_map>

命名空间：__gnu_cxx;

声明：hash_map<key_type, value_type, hash_func> h;

h.find(key)判断某个key是否存在hash_map中；

h[key] = value将value存储在key位上；

h[key] 访问对应的value

h.begin()哈希表的起始位置

h.end()哈希表的结束位置



#### 标准

Unordered_map类：字符串

头文件：unorder_msp

命名空间：std

声明：unorder_map<key_type, value_type, hash_func> h

h.find(key)判断某个key是否存在hash_map中；

h[key] = value将value存储在key位上；

h[key] 访问对应的value

h.begin()哈希表的起始位置

h.end()哈希表的结束位置

不用std using namespase 把所有的标识符倒入



#### 静态成员变量

1.在普通成员变量前用static修饰

2.隶属与整个类，不属于某个对象，是每个对象共有的

3.生命周期与全局变量的生命周期相同，在程序运行完之后释放

4.静态成员变量不占用对象存储空间，在类内部声明，在类外部定义

