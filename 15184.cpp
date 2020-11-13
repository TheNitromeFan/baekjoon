#include <cstdio>

int main(){
	char s[260];
	fgets(s, 255, stdin);
	int cnt[26] = {};
	for(int i = 0; s[i] != '\0'; ++i){
		if(s[i] >= 'A' && s[i] <= 'Z'){
			++cnt[s[i] - 'A'];
		}else if(s[i] >= 'a' && s[i] <= 'z'){
			++cnt[s[i] - 'a'];
		}
	}
	for(char c = 'A'; c <= 'Z'; ++c){
		printf("%c | ", c);
		for(int i = 0; i < cnt[c - 'A']; ++i){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
