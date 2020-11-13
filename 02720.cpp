#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int c;
		scanf("%d", &c);
		int q = c / 25;
		c %= 25;
		int d = c / 10;
		c %= 10;
		int n = c / 5;
		int p = c % 5;
		printf("%d %d %d %d\n", q, d, n, p);
	}
	return 0;
}
