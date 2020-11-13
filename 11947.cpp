#include <cstdio>
#include <algorithm>
#define MAX 1000000

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		long long n;
		scanf("%lld", &n);
		long long ten_power = 1;
		while(ten_power <= n){
			ten_power *= 10;
		}
		long long ans = 0;
		if(n >= ten_power / 2){
			ans = ten_power / 2 * (ten_power / 2 - 1);
		}else{
			ans = std::max(n * (ten_power - 1 - n), ten_power / 20 * (ten_power / 20 - 1));
		}
		printf("%lld\n", ans);
	}
	return 0;
}
