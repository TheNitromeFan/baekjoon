#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	static long long memo[1000001] = {};
	for(int i = 1; i <= 1000000; ++i){
		for(int j = 1; j * i <= 1000000; ++j){
			memo[j * i] += i;
		}
		memo[i] += memo[i - 1];
	}
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		scanf("%d", &n);
		printf("%lld\n", memo[n]);
	}
	return 0;
}
