#include <cstdio>
#include <cmath>

int main(){
	int p, a, b, c, d, n;
	scanf("%d %d %d %d %d %d", &p, &a, &b, &c, &d, &n);
	double max = -4 * p - 1;
	double maxDec = 0;
	for(int i = 1; i <= n; ++i){
		double price = p * (sin(a * i + b) + cos(c * i + d) + 2);
		if(max < price){
			max = price;
		}
		if(maxDec < max - price){
			maxDec = max - price;
		}
	}
	printf("%.9lf", maxDec);
	return 0;
}
