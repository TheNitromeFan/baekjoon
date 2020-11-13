#include <cstdio>

int gcd(int a, int b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

int main(){
	int r, g;
	scanf("%d %d", &r, &g);
	int gc = gcd(r, g);
	for(int i = 1; i <= gc; ++i){
		if(gc % i == 0){
			printf("%d %d %d\n", i, r / i, g / i);
		}
	}
	return 0;
}
