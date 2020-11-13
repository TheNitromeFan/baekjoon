#include <cstdio>

int main(){
	int n, k, w, p;
	scanf("%d %d %d %d", &n, &k, &w, &p);
	printf("%d", (w - 1) / p + 1);
	return 0;
}
