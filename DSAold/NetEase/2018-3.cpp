/*
链接：https://www.nowcoder.com/questionTerminal/97bc02e432bb4744a9e666b6c93d4479
来源：牛客网

一个由小写字母组成的字符串可以看成一些同一字母的最大碎片组成的。例如,"aaabbaaac"是由下面碎片组成的:'aaa','bb','c'。牛牛现在给定一个字符串,请你帮助计算这个字符串的所有碎片的平均长度是多少。

输入描述:

输入包括一个字符串s,字符串s的长度length(1 ≤ length ≤ 50),s只含小写字母('a'-'z')


输出描述:

输出一个整数,表示所有碎片的平均长度,四舍五入保留两位小数。

如样例所示: s = "aaabbaaac"
所有碎片的平均长度 = (3 + 2 + 3 + 1) / 4 = 2.25
*/

#include "iostream"
#include "stdio.h"
using namespace std;
int main() {
    char a[60] ;
    int i;
double aa ,b ,sum;
        cin>>a;
      aa = 0.0,b =0.0,sum = 0.0;
      for(i = 0;a[i]!='\0';i++){
	  if(a[i]==a[i+1]){
         aa=aa+1.0;
      }
      if(a[i]!=a[i+1]){
	    aa=aa+1.0;
	    sum+=aa;
	    aa = 0;
	    b = b +1.0;
     }
   } 
    printf("%.2f",sum/b);
}

