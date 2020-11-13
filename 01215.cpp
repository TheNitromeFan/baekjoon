#include <iostream>

int main(){
	long long n, k;
	std::cin >> n >> k;
	long long ans = 0LL;
	long long i = 1;
	while(i <= n){
		long long j = k / i, r = k % i;
		if(j == 0){
			ans += r * (n - i + 1);
			i = n + 1;
		}else{
			long long s = r/j;
			if(s + 1 > n - i + 1){
				s = n - i;
			}
			ans += (r + r - s * j) * (s + 1) / 2;
			i += s + 1;
		}
	}
	std::cout << ans;
	return 0;
}
