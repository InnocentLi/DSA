#include<bits/stdc++.h>
using namespace std;
int main(){
     int l,r;
     int ll,rr;
     int suml,sumr;
     int x;
     cin>>l>>r;
     l = l-1;
     ll = l/3;
     rr = r/3;
    // cout<<"ll:"<<ll<<"rr"<<rr<<endl;
     if(l%3 ==0||l%3==1){
        suml = ll*2;
     }
     else if(l%3 == 2 ){
        suml = ll*2 + 1;
     }


     if(r%3==0||r%3==1){
        sumr = rr*2;
      //   x = rr%3;
      //  cout<<x<<endl;
      //   cout<<"yu10"<<endl;
     }else if(r%3 == 2){
        sumr = rr*2 + 1;
      //  cout<<"yu2"<<endl;
     }
     cout<<sumr-suml<<endl;



   }
