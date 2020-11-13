#include <cstdio>

int main(){
	int s;
	scanf("%d", &s);
	printf("%d:\n", s);
	for(int n = 2; n <= s / 2 + 1; ++n){
		if(s % (2 * n - 1) == 0 || (s + n - 1) % (2 * n - 1) == 0){
			printf("%d,%d\n", n, n - 1);
		}
		if(s % n == 0){
			printf("%d,%d\n", n, n);
		}
	}
	return 0;
}
