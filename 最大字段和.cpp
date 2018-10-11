#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	 int a[]={-1,-2,4,3,-2,6,3,0,-2,3,-2,-19};    //测试用例
	       int length=12;
	       int cur=a[0];
	       int max=a[0];
	       for(int i=0;i<length;i++)
	       {
		  	 if(cur<0)
				cur=0;
		  	 cur+=a[i];
		  	 if(cur>max)
				max=cur;
	       }
	cout<<max<<endl;
}
