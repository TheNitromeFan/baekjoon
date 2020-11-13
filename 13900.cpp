#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	long long sum = 0, square_sum = 0;
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		sum += x;
		square_sum += x * x;
	}
	printf("%lld", (sum * sum - square_sum) / 2);
	return 0;
}
