#include <cstdio>

int gcd(int a, int b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		while(a > 1){
			int x = b / a + 1;
			a = a * x - b;
			b = b * x;
			int g = gcd(a, b);
			a /= g;
			b /= g;
		}
		printf("%d\n", b);
	}
	return 0;
}
