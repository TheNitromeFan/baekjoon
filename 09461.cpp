#include <cstdio>


int main(){
	long long p[101] = {0, 1, 1, 1, 2, 2};
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		scanf("%d", &n);
		if(p[n]){
			printf("%lld\n", p[n]);
			continue;
		}
		for(int i = 6; i <= n; ++i){
			p[i] = p[i-1] + p[i-5];
		}
		printf("%lld\n", p[n]);
	}
	return 0;
}
