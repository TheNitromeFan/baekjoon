#include <cstdio>

int main(){
	long long total_sum = 0, squares_sum = 0;
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		total_sum += x;
		squares_sum += x * x;
	}
	printf("%lld", (total_sum * total_sum - squares_sum) / 2);
	return 0;
}
