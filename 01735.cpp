#include <cstdio>

int gcd(int a, int b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

int main(){
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int n = a * d + b * c, den = b * d;
	int g = gcd(n, den);
	printf("%d %d", n / g, den / g);
	return 0;
}
