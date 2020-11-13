#include <cstdio>
#define MAX (5000000 + 1)

int main(){
	int n;
	scanf("%d", &n);
	static char s[MAX];
	scanf("%s", s);
	long long ans = 0;
	int cur = 0;
	for(int i = 0; i < n; ++i){
		if(s[i] >= '0' && s[i] <= '9'){
			cur = cur * 10 + s[i] - '0';
		}else{
			ans += cur;
			cur = 0;
		}
	}
	ans += cur;
	printf("%lld", ans);
	return 0;
}
