#include <cstdio>

int main(){
	int a, b, n;
	scanf("%d %d %d", &a, &b, &n);
	int h = a * n + b;
	for(int i = 0; i < n; ++i){
		printf("%d ", h);
		h += b;
	}
	return 0;
}
