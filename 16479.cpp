#include <cstdio>
#include <cstdlib>

int main(){
	int k, d1, d2;
	scanf("%d %d %d", &k, &d1, &d2);
	double diff = abs(d1 - d2) / 2.0;
	printf("%f", k * k - diff * diff);
	return 0;
}
