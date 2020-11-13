#include <cstdio>

int gcd(int a, int b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		int g = gcd(a, b);
		printf("%d %d\n", a / g * b, g);
	}
	return 0;
}
