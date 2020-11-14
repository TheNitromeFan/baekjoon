#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	char s[100001];
	scanf("%s", s);
	int i = 0;
	int cnt = 0;
	while(i < n){
		if(i + 1 < n && s[i] != s[i + 1]){
			++cnt;
			i += 2;
		}else{
			++i;
		}
	}
	printf("%d", cnt);
	return 0;
}
