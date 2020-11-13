#include <cstdio>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	long long cows = 0;
	long long powerOf4 = 1;
	while(n % 2 == 1 && m % 2 == 1){
		cows += powerOf4;
		powerOf4 *= 4;
		n /= 2;
		m /= 2;
	}
	printf("%lld", cows);
	return 0;
}
