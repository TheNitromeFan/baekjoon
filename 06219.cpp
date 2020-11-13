#include <cstdio>

bool prime(int n){
	for(int p = 2; p * p <= n; ++p){
		if(n % p == 0){
			return false;
		}
	}
	return true;
}

bool contains(int n, int digit){
	while(n){
		if(n % 10 == digit){
			return true;
		}
		n /= 10;
	}
	return false;
}

int main(){
	int a, b, d;
	scanf("%d %d %d", &a, &b, &d);
	int ans = 0;
	for(int i = a; i <= b; ++i){
		if(prime(i) && contains(i, d)){
			++ans;
		}
	}
	printf("%d", ans);
	return 0;
}
