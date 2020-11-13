#include <cstdio>
#include <cstdlib>

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", (int)(2.0 * abs(b - a) / b));
	return 0;
}
