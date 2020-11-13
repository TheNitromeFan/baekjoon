#include <cstdio>

int sum_of_digits_in_base_k(int n, int k){
	int ret = 0;
	while(n){
		ret += n % k;
		n /= k;
	}
	return ret;
}

int main(){
	int n;
	scanf("%d", &n);
	int max_val = 0, max_idx = 0;
	for(int i = 2; i <= n; ++i){
		int cmp = sum_of_digits_in_base_k(n, i);
		if(max_val < cmp){
			max_val = cmp;
			max_idx = i;
		}
	}
	printf("%d %d", max_val, max_idx);
	return 0;
}
