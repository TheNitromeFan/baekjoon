#include <cstdio>

bool nondec(long long n){
	int r = 10;
	while(n){
		if(n % 10 > r){
			return false;
		}
		r = n % 10;
		n /= 10;
	}
	return true;
}

long long last_tidy(long long n){
	if(nondec(n)){
		return n;
	}
	long long subtrahend = (n % 10) + 1;
	n -= subtrahend;
	subtrahend = 10;
	while(!nondec(n)){
		if(n % (subtrahend * 10) == (subtrahend * 10) - 1){
			subtrahend *= 10;
		}
		n -= subtrahend;
	}
	return n;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; ++i){
		long long n;
		scanf("%lld", &n);
		printf("Case #%d: %lld\n", i, last_tidy(n));
	}
	return 0;
}
