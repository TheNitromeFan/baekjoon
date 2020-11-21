#include <cstdio>

int flips(char s[1001], int k){
	int ret = 0;
	int i;
	for(i = 0; s[i + k - 1] != '\0'; ++i){
		if(s[i] == '-'){
			++ret;
			for(int j = i; j < i + k; ++j){
				if(s[j] == '+'){
					s[j] = '-';
				}else{
					s[j] = '+';
				}
			}
		}
	}
	for(; s[i] != '\0'; ++i){
		if(s[i] == '-'){
			return -1;
		}
	}
	return ret;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 1; a0 <= t; ++a0){
		char s[1001];
		int k;
		scanf("%s %d", s, &k);
		printf("Case #%d: ", a0);
		int f = flips(s, k);
		if(f != -1){
			printf("%d\n", f);
		}else{
			printf("IMPOSSIBLE\n");
		}
	}
	return 0;
}
