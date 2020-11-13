#include <cstdio>

int main(){
	int x, y;
	scanf("%d %d", &x, &y);
	long long n = 0;
	long long powerOf2 = 1;
	for(int i = 0; i < 16; ++i){
		n += y % 2 * powerOf2;
		powerOf2 *= 2;
		y /= 2;
		n += x % 2 * powerOf2;
		powerOf2 *= 2;
		x /= 2;
	}
	printf("%lld", n);
	return 0;
}
