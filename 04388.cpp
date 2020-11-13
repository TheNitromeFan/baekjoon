#include <cstdio>

int main(){
	while(true){
		long long a, b;
		scanf("%lld %lld", &a, &b);
		if(a == 0 && b == 0){
			break;
		}
		int ans = 0;
		long long carry = 0;
		while(a > 0 || b > 0){
			carry = ((a % 10) + (b % 10) + carry) / 10;
			if(carry){
				++ans;
			}
			a /= 10;
			b /= 10;
		}
		printf("%d\n", ans);
	}
	return 0;
}
