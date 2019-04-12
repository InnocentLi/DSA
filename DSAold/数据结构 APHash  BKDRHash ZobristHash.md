```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int APHash(const char *str){
	int hash = 0;
	for(int i = 0; str[i]; i++){
		if(i & 1){//i为奇数；
			hash ^= (hash << 7) ^ str[i] ^ (hash >> 3);
		}else{
			hash ^= (~((hash << 11) ^ str[i] ^ (hash >> 5)));
		}
	}
	return hash & 0x7fffffff;//为负数时过滤负号；
}

int BKDRHash(const char *str){
	int hash = 0, seed = 131;//seed与256互素；
	for(int i = 0; str[i]; i++){
		hash = hash * seed + str[i];
	}
	
	return hash & 0x7fffffff;
}

int zobrist_table[50][256] = {0};

void init_zobrist_table(){
	for(int i = 0; i < 50; i++){
		for(int j = 0; j < 256; j++){
			zobrist_table[i][j] = rand();
		}
	}
	return ;
}

int ZobristHash(const char * str){
	static int flag = 1;
	if(flag){
		flag = 0;
		init_zobrist_table();
	}
	int hash = 0;
	for(int i = 0; str[i]; i++){
		hash ^= zobrist_table[i][str[i]];
	}
	return hash & 0x7fffffff;
}
int main(){
	srand(time(0));
	char str1[50] = {0}, str2[50] = {0};
	for(int i = 0; i < 16; i++){
		str1[i] = (i & 1) ? 'a' : 'b';
	}
	for(int i = 0; i < 32; i++){
		str2[i] = (i & 1) ? 'a' : 'b';
	}
	printf("BKDRHash(%s) = %d\n",str1,BKDRHash(str1));
	printf("BKDRHash(%s) = %d\n",str2,BKDRHash(str2));
	printf("APHash(%s) = %d\n",str1,APHash(str1));
	printf("APHash(%s) = %d\n",str2,APHash(str2));
	printf("ZobristHash(%s) = %d\n",str1,ZobristHash(str1));
	printf("ZobristHash(%s) = %d\n",str2,ZobristHash(str2));		
	return 0;
}
```

##### 输出结果

>BKDRHash(babababababababa) = 253938776
>
>BKDRHash(babababababababababababababababa) = 514643632
>
>APHash(babababababababa) = 274007444
>
>APHash(babababababababababababababababa) = 1469572165
>
>ZobristHash(babababababababa) = 1160426730
>
>ZobristHash(babababababababababababababababa) = 870444918

