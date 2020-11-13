#include <cstdio>

int main(){
	while(true){
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		long long a[10000];
		long long sum = 0;
		for(int i = 0; i < n; ++i){
			scanf("%lld", &a[i]);
			sum += a[i];
		}
		int ans = 0;
		for(int i = 0; i < n; ++i){
			if(a[i] * n <= sum){
				++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
