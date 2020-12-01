#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 1; a0 <= t; ++a0){
		char s[101];
		scanf("%s", s);
		char last = s[0];
		int idx = 0;
		int cnt = 0;
		while(s[idx] != '\0'){
			while(s[idx] == last){
				++idx;
			}
			if(s[idx] != '\0'){
				++cnt;
				last = s[idx];
			}
		}
		if(last == '-'){
			++cnt;
		}
		printf("Case #%d: %d\n", a0, cnt);
	}
	return 0;
}
