封装：我该有的和我该做的

继承：叫一声爸爸，开启财富之门

多态：我就是我，不一样的烟火

#### 继承【从子类到父类的设计】

父类【基类】

子类【派生类】

即使是子类也不能访问name属性

先得初始化父类的空间，才能初始化子类的内存空间

```c++
class Animal{//Animal是父类；
	public :
		string name(){ return this->__name; }
	private:
		string __name;
};
class Cat : public Animal{
	//Cat是子类；共有继承方式
};
```

public private protected 是针对成员的属性访问权限，以及类的继承方式设定的

| 访问方式          | 访问权限     |
| ----------------- | ------------ |
| pubilc            | 共有访问权限 |
| private           | 私有访问权限 |
| protected【继承】 | 受保护的权限 |

#### 继承—子类访问权限

|                   | public【公有继承】 | protected【保护继承】 | private【私有继承】 |
| ----------------- | ------------------ | --------------------- | ------------------- |
| public【父类】    | 可以               | 可以                  | 可以                |
| protected【父类】 | 可以               | 可以                  | 可以                |
| private【父类】   | X                  | X                     | X                   |

子类仅仅能继承父类中的public 和 protected

 基类中      继承方式             子类中

    public     ＆ public继承        => public
    public     ＆ protected继承     => protected   
    public     ＆ private继承       => private
    
    protected  ＆ public继承        => protected
    protected  ＆ protected继承     => protected   
    protected  ＆ private继承       => private
    
    private    ＆ public继承        => 子类无权访问
    private    ＆ protected继承     => 子类无权访问
    private    ＆ private继承       => 子类无权访问



#### 问题

#### 不同的继承方式当你把属性和方法从父类中继承到子类的时候，对于子类对象这个方法的对外的访问控制权限是什么？

|                   | public【共有继承】 | protected【保护继承】 | private【私有继承】 |
| ----------------- | ------------------ | --------------------- | ------------------- |
| public【父类】    | public             | protected             | private             |
| protected【父类】 | protected          | protected             | private             |
| private【父类】   | X                  | X                     | X                   |

#### 实验

哪种情况下子类继承父类后可以被访问；

| 父类     | 子类   |
| -------- | ------ |
| 1.struct | class  |
| 2.struct | struct |
| 3.class  | struct |
| 4.class  | class  |

1.struct父类，class子类

```c++
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

//结构体和类默认权限对于继承的影响；
struct A{
public:
	A() : x(3){}
	int x;	
};

struct B : A{
	
};
//由于B类是A的继承类，我们在主函数中调用B,看看能不能返回父类A的值；

int main(){
	B a;
	cout << a.x << endl;
	return 0;
}
```

>3

2.struct父类，class子类

>编译出错

3.父类class，子类struct

>3

4.父类class，子类class

>编译出错





```c++
class Animal{
	public :
		Animal(string name) : __name(name) {}
		string name() { return this->__name; }
		string color;
	protected:
		string __name;
};
class Cat : public Animal{
	public :
		Cat():Animal("temp cat"){}
		Cat(string name) : Animal(name) {}
		void set_name(string n){
			this->__name = n;
		}
};

```

#### 先构造父类，再构造子类

Cat ()   初始化列表 {

	构造逻辑
	
	没有对父类进行构造的话，很有可能不合法；

}

数据存储在父类的存储区

匹配构造函数，完成构造过程

父类没有默认构造函数，必须传参数进去，父类的构造函数必须放入子类的传参列表中

#### 匹配构造函数是从子类到父类

#### 完成构造函数是从父类到子类

#### 子类与父类的构造顺序

```c++
#include <iostream>
#include <string.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;

//结构体和类默认权限对于继承的影响；
struct Animal{
	Animal(string name) :name(name){}
private:
	string name;	
};

class Bat : public Animal{
	
};
//由于B类是A的继承类，我们在主函数中调用B,看看能不能返回父类A的值；

int main(){
	Bat b;
	return 0;
}
```

>编译报错：Animal父类并没有默认构造函数，导致子类也没有构造函数



```c++
class Bat : public Animal{
public:
	Bat();//构造子类
};
```

>编译出错：必须显示的初始化基类Animal
>



```c++
class Bat : public Animal{
public:
	Bat() : Animal("bat"){}
};
```

>编译通过



```c++
#include <iostream>
#include <string.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;

//结构体和类默认权限对于继承的影响；
struct Animal{
	Animal(string name) :name(name){
		cout << "animal constructor" << endl;
	}
private:
	string name;	
};

class Bat : public Animal{
public:
	Bat() : Animal("bat"){
		cout << "bat constructor" << endl;
	}
};
//由于B类是A的继承类，我们在主函数中调用B,看看能不能返回父类A的值；

int main(){
	Bat b;
	return 0;
}
```

>animal constructor
>
>bat constructor

先执行Animal的构造逻辑，再执行Bat的构造逻辑；

#### 子类的内存大小

```c++
#include <iostream>
#include <string.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;

//结构体和类默认权限对于继承的影响；
struct Animal{
	Animal(string name) :name(name){
		cout << "animal constructor" << endl;
	}
private:
	string name;	
};

class Bat : public Animal{
public:
	Bat() : Animal("bat"){
		cout << "bat constructor" << endl;
	}
	
};
//由于B类是A的继承类，我们在主函数中调用B,看看能不能返回父类A的值；

int main(){
	Bat b;
	cout << sizeof(Bat) << endl;
	//因为开辟一个子类的对象，不仅要开辟当前子类的空间，还需要开辟父类的空间；等于子类与父类相加之和；
	cout << sizeof(Animal) << endl;
	return 0;
}
```

>animal constructor
>
>bat constructor
>
>24
>
>24



```c++
class Bat : public Animal{
public:
	Bat() : Animal("bat"){
		cout << "bat constructor" << endl;
	}
	int x;
};
```

> animal constructor
>
> bat constructor
>
> 32
>
> 24

```c++
class Bat : public Animal{
public:
	Bat() : Animal("bat"){
		cout << "bat constructor" << endl;
	}
	int x, y;
};
```

> animal constructor
>
> bat constructor
>
> 32
>
> 24

```c++
class Bat : public Animal{
public:
	Bat() : Animal("bat"){
		cout << "bat constructor" << endl;
	}
	int x, y, z;
};
```

>animal constructor
>
>bat constructor
>
>40
>
>24





![屏幕快照 2018-09-12 下午7.31.35的副本](/Users/hanxu/Desktop/blog图片文件/屏幕快照 2018-09-12 下午7.31.35的副本.png)

不允许棱形继承，也就是B的父类是A，C的父类是A，D是B和C的子类

接口类内部没有函数方法，全都是声明【允许棱形继承】

#### 抽象类不能产生对象

![屏幕快照 2018-09-12 下午7.35.33](/Users/hanxu/Desktop/blog图片文件/屏幕快照 2018-09-12 下午7.35.33.png)



在上图中B是子类，A是父类

![屏幕快照 2018-09-12 下午7.38.24](/Users/hanxu/Desktop/blog图片文件/屏幕快照 2018-09-12 下午7.38.24.png)

#### 继承—数组模版

```c++
#include <iostream>
#include <string.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostream;

//结构体和类默认权限对于继承的影响；
struct Animal{
	Animal(string name) :__name(name){
		cout << "animal constructor" << endl;
	}
private:
	string __name;	
};

class Bat : public Animal{
public:
	Bat() : Animal("bat"){
		cout << "bat constructor" << endl;
	}
	
};
//由于B类是A的继承类，我们在主函数中调用B,看看能不能返回父类A的值；
template<typename T>
class Array{
public :
	Array(int n) : n(n){
		this->data = (T *)malloc(sizeof(T) * n);
	}
	T &operator[](int ind){
		if(ind < 0 || ind >= this->n) return this->temp;
		return this->data[ind];
	}
	void output(){
		for(int i = 0; i < this->n; i++){
			cout << this->data[i]<< endl;
		}
	}
private :
	int n;
	T *data, temp;
};


int main(){
	Array<Bat> arr(10);
	for(int i = 0; i < 10; i++){
		arr[i] = i + 1;
	}
	arr.output();
	return 0;
}
```

>1
>
>2
>
>3
>
>4
>
>5
>
>6
>
>7
>
>8
>
>9
>
>10

