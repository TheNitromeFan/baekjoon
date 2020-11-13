#include <cstdio>

int gcd(int a, int b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

int main(){
	int n, m;
	scanf("%d:%d", &n, &m);
	int g = gcd(n, m);
	printf("%d:%d", n / g, m / g);
	return 0;
}
