#include <cstdio>

bool prime(int n){
	if(n == 0 || n == 1){
		return false;
	}
	for(int p = 2; p * p <= n; ++p){
		if(n % p == 0){
			return false;
		}
	}
	return true;
}

void backtrack(int n, int cur, int x){
	if(cur == n){
		printf("%d\n", x);
		return;
	}
	for(int y = x * 10 + 1; y <= x * 10 + 9; ++y){
		if(prime(y)){
			backtrack(n, cur + 1, y);
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);
	backtrack(n, 0, 0);
	return 0;
}
