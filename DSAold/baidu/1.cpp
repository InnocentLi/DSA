//
//   百度某一面试题

#include <bits/stdc++.h>
using namespace std;

char a[100];
char s[100];
int main()
{
    while(cin >> s) {
        int ii = 0;
        int len = strlen(s);
        char t = s[0];
        int idx = 0;
        while(idx < len) {
            t = s[idx];
            for(int i = idx; i < len; i++) {
                if(s[i] > t ) {
                    t = s[i];
                    idx = i;
                }
            }
            a[ii++] = t;
            idx++;
        }
        a[ii] = '\0';
        cout << a << endl;
    }

}
