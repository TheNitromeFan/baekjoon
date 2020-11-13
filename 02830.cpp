#include <cstdio>
#define MAX 1000000

int main(){
	int n;
	scanf("%d", &n);
	static int nums[MAX];
	for(int i = 0; i < n; ++i){
		scanf("%d", &nums[i]);
	}
	long long ans = 0;
	for(long long p = 1; p <= MAX; p *= 2){
		int zeroes = 0, ones = 0;
		for(int i = 0; i < n; ++i){
			if(nums[i] % 2 == 0){
				++zeroes;
			}else{
				++ones;
			}
			nums[i] /= 2;
		}
		ans += p * zeroes * ones;
	}
	printf("%lld", ans);
	return 0;
}
