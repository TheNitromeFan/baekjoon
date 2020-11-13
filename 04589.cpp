#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	printf("Gnomes:\n");
	for(int i = 0; i < n; ++i){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		printf("%s\n", (a > b && b > c) || (a < b && b < c) ? "Ordered" : "Unordered");
	}
	return 0;
}
