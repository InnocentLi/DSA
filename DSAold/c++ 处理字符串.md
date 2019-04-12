#### 复制字符串

```c++
char s[] = "abcdefg";
char b[4];
strncpy(b, s + 2, 3);
b[3] = '\0';
```



```c++
string s = "abcdefg";
string d(begin(s) + 2, begin(s) + 5);
```



#### 替换更长更短子字符串

```c
int main() {
	char a[10] = "abcdefg";
	memmove(a + 6, a + 5, strlen(a + 5) + 1);
	strncpy(a + 2, "XYZW", 4);
	for(int i = 0; i < 10; i++){
		cout << a[i] ;
	}
	cout << endl;
	char b[10] = "abcdefg";
	strncpy(b + 2, "UV", 2);
	memmove(b + 4, b + 5, strlen(b + 5) + 1);
	for(int i = 0; i < 10; i++){
			cout << b[i] ;
	}
	return 0;
}
```

>abXYZWfg
>
>abUVfg

```c++
int main() {
	string a = "abcdefg";
	a.replace(begin(a) + 2, begin(a) + 5, "XYZW");

	string b = "abcdefg";
	b.replace(begin(b) + 2, begin(b) + 5, "UV");
	cout << a << endl;
	cout << b << endl;
	return 0;
}
```

>abXYZWfg
>
>abUVfg



#### 查找子字符串

```c
char s[] = "abcdefg";
char* x = strstr(s, "cde"); // x == s + 2
char* y = strstr(s, "CDE"); // y == nullptr
printf("%s\n", x);
printf("%s\n", y);
```

>cdefg
>
>(null)

```c++
string s = "abcdefg";
auto x = s.find("cde"); // x == 2
auto y = s.find("CDE"); // y == string::npos
```



#### 把字符串里所有某个子串换成另一个子串

```c++
void Replace(string& str, const string& toFind, const string& toReplace)
{
    while (true)
    {
        auto pos = str.find(toFind);
        if (pos == string::npos)
        {
            break;
        }
        str.replace(begin(str) + pos, begin(str) + pos + toFind.size(), toReplace);
    }
}
```





#### lamada表达式

1.语法：[捕获]（参数）{一些语句}

2.[捕获]：捕获主要控制lamada表达式的函数体可以看见外面的什么名字。空的话表示什么都不给看

3.（参数）：跟函数的参数一样

4.{一些语句}：lamada表达式的函数体

