#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	static int a[1000001];
	long long sum = 0;
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
		sum += a[i];
	}
	long long squared_sum = 0;
	long long max = 0;
	for(int i = 1; i <= n; ++i){
		squared_sum += a[i] * a[i];
		sum -= a[i];
		if(max < squared_sum * sum){
			max = squared_sum * sum;
		}
	}
	printf("%lld", max);
	return 0;
}
