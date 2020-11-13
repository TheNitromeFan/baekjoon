#include <cstdio>

int main(){
	long long l, n;
	scanf("%lld %lld", &l, &n);
	long long rolls = 1;
	long long div = n;
	while(div > 1){
		long long rem = l % div;
		if(rem == 0){
			break;
		}
		++rolls;
		div -= rem;
		// printf("%lld\n", div);
	}
	printf("%lld", rolls);
	return 0;
}
