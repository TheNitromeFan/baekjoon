#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int best = 10000000;
	int besta = 0, bestb = 0, bestc = 0;
	for(int a = 1; a * a * a <= n; ++a){
		for(int b = a; a * b * b <= n; ++b){
			if(n % a != 0 || n / a % b != 0){
				continue;
			}
			int c = n / a / b;
			if(best > a * b + b * c + c * a){
				best = a * b + b * c + c * a;
				besta = a;
				bestb = b;
				bestc = c;
			}
		}
	}
	printf("%d %d %d", besta, bestb, bestc);
	return 0;
}
