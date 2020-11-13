#include <cstdio>

int zeroes(int n){
	if(n == 0){
		return 1;
	}
	int ret = 0;
	while(n){
		if(n % 10 == 0){
			++ret;
		}
		n /= 10;
	}
	return ret;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int n, m;
		scanf("%d %d", &n, &m);
		int ans = 0;
		for(int j = n; j <= m; ++j){
			ans += zeroes(j);
		}
		printf("%d\n", ans);
	}
	return 0;
}
