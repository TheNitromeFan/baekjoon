#include <cstdio>
#include <cmath>

int gcd(int a, int b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

int main(){
	int g, ell;
	scanf("%d %d", &g, &ell);
	int a = sqrt(ell / g);
	while(true){
		if((ell / g) % a == 0 && gcd(a, (ell / g / a)) == 1){
			printf("%d %d", g * a, ell / a);
			break;
		}
		--a;
	}
	return 0;
}
