#include <cstdio>
#define MAX 100001

int main(){
	int n;
	scanf("%d", &n);
	char s[MAX];
	scanf("%s", s);
	int c[MAX] = {}, w[MAX] = {};
	if(s[0] == 'C'){
		++c[0];
	}else if(s[0] == 'W'){
		++w[0];
	}
	for(int i = 1; i < n; ++i){
		c[i] = c[i - 1];
		w[i] = w[i - 1];
		if(s[i] == 'C'){
			++c[i];
		}else if(s[i] == 'W'){
			++w[i];
		}
	}
	long long ans = 0;
	for(int i = 1; i < n - 1; ++i){
		if(s[i] == 'O'){
			ans += (long long)c[i - 1] * (w[n - 1] - w[i]);
		}
	}
	printf("%lld", ans);
	return 0;
}
