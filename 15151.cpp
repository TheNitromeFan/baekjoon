#include <cstdio>
#include <cmath>

int main(){
	int k, d;
	scanf("%d %d", &k, &d);
	printf("%d", (int)log2(d / (double)k + 1));
	return 0;
}
