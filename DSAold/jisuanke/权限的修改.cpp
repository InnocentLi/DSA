#include <stdio.h>
int main() {
    int r[3]={0};
    char b[3]="000";
	scanf("%s",b);
	for(int i = 0;i<3;i++){
		if(b[i]=='r'){
			r[0]=1;
		}
		if(b[i]=='w'){
			r[1]=1;
        }
        if(b[i]=='x'){
	        r[2]=1; 
        }
	}
	char c[3]="00";
    while(scanf("%s",c)!=EOF){
	    if(c[0]=='+'){
		       if(c[1]=='r'){
					r[0]=1;
				}
				if(c[1]=='w'){
					r[1]=1;
		        }
		        if(c[1]=='x'){
			        r[2]=1; 
		        }
        }else if(c[0]=='-'){
	        if(c[1]=='r'){
				r[0]=0;
			}
			if(c[1]=='w'){
				r[1]=0;
	        }
	        if(c[1]=='x'){
		        r[2]=0; 
	        }
         }
    }
    printf("%d\n",r[0]*4+r[1]*2+r[2]*1);
	return 0;
}
