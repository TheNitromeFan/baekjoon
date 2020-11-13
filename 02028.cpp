#include <cstdio>

bool isSelfSquare(int n){
	int pow10 = 1;
	while(pow10 <= n){
		pow10 *= 10;
	}
	return n * n % pow10 == n % pow10;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int n;
		scanf("%d", &n);
		printf("%s\n", isSelfSquare(n) ? "YES" : "NO");
	}
	return 0;
}
