#include <cstdio>

int main(){
	char s[1000000];
	scanf("%s", s);
	int cnt = 0;
	for(int i = 1; s[i] != '\0'; ++i){
		if(s[i] != s[i - 1]){
			++cnt;
		}
	}
	printf("%d", (cnt + 1) / 2);
	return 0;
}
