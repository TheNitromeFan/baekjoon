#include <cstdio>

int gcd(int a, int b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

int main(){
	int ab, ac, bd;
	while(scanf("%d %d %d", &ab, &ac, &bd) == 3){
		int n = ab * ac, d = bd - ac;
		int g = gcd(n, d);
		printf("%d/%d\n", n / g, d / g);
	}
	return 0;
}
