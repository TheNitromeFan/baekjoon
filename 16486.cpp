#include <cstdio>
#include <cmath>
#define PI acos(-1)

int main(){
	int d1, d2;
	scanf("%d %d", &d1, &d2);
	printf("%f", 2 * PI * d2 + 2 * d1);
	return 0;
}
