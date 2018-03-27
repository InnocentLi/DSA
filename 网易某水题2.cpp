#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int l = 0;
    int r = 0;
    int re;
    char a[2000];
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    for(int i = 0;i<n;i++){
        if(a[i]=='L'){
            l++;
        }
        if(a[i]=='R'){
            r++;
        }
    }
    l = l%4;
    r = r%4;
    re = l-r;
    if(re==0){
        cout<<"N"<<endl;
    }
    else if(re==-1){
        cout<<"E"<<endl;
    }
    else if(re==1){
        cout<<"W"<<endl;
    }else if(re==2||re==-2){
        cout<<"S"<<endl;
    }else if(re == 3){
        cout<<"W"<<endl;
    }else if(re== -3){
        cout<<"E"<<endl;
    }

   }
