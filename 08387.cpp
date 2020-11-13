#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	char s1[100001], s2[100001];
	scanf("%s", s1);
	scanf("%s", s2);
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		if(s1[i] == s2[i]){
			++cnt;
		}
	}
	printf("%d", cnt);
	return 0;
}
