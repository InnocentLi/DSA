#### qsort

```c++
#include <stdlib.h>

int compare(const void *x, const void *y){
    return *reinterpret_cast<const int*>(y) - *reinterpret_cast<const int*>(x);
}

int main(){
    int a[] = {2, 4, 5, 3, 1};
    qsort(
        a,
        sizeof(a) / sizeof(*a);
        sizeof(*a);
        &compare
    );
}
```

1.qsort的比较函数返回-1，0，1来表示比较结果

2.每一次调用qsort都需要重复传进关于数组和元素的大小信息

3.比较函数需要独立成一个函数

4.比较的逻辑与排序的逻辑被隔开。如果比较逻辑较为复杂的话，会使这两部分相隔甚远

5.普遍情况下性能较低



#### vector

```c++
#include <vector>
#include <algorithm>

int main(){
    vector<int> a ={2, 4, 5, 3, 1};
    sort(
        begin(a);
        end(a);
        [](int x, int y) {return x >= y; }
    );
}
```

1.std::sort的比较函数返回true，false来表示两个数组元素的位置是否正确

2.std::sort可以根据类型来推导各项长度信息

3.不需要专门为了比较而创造一个新的函数

4.可以使用lambda表达式来让代码变得更紧凑，所有相关的代码都写在了一起，十分易读

5.普遍情况下性能较高



根据各项测试，std::sort的性能要比qsort好不少，其中一个重要的原因就是，编译器回根据不同类型的vector特化出相应的std::sort,然后分别进行优化。qsort配合compare函数就丧失了类型信息，导致此类优化无法完成



```c++
template<typename T, ...>
class vector
{
...
    T& operator[](uintptr_t index);
    T& at(uintptr_t index);
...
// uintptr_t在CPU是32位或64位的情况下，通常都是unsigned __int32或unsigned __int64。
};
```

operator[]不检查下标范围，如果错误了就返回一个不知道指向哪里的引用；at检查下标范围，如果出错就抛出std::out_of_range异常