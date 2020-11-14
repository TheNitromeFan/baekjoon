#include <cstdio>

int main(){
	int a, b, n;
	scanf("%d %d %d", &a, &b, &n);
	printf("%d", ((n - b - 1) / (b - a) + 1) * 2 + 1);
	return 0;
}
