#include <cstdio>

/*
long long pow(long long a, int x){
	if(x == 0){
		return a;
	}else if(x % 2 == 0){
		long long b = pow(a, x / 2);
		return b * b;
	}else{
		long long b = pow(a, x / 2);
		return b * b * a;
	}
}
*/

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		long long n;
		scanf("%lld", &n);
		int start = 0;
		for(int i = 0; i < 6; ++i){
			int x;
			scanf("%d", &x);
			start += x;
		}
		int days = 0;
		long long power_of_4 = 1;
		while(true){
			++days;
			if(power_of_4 * start > n){
				break;
			}
			power_of_4 *= 4;
		}
		printf("%d\n", days);
	}
	return 0;
}
