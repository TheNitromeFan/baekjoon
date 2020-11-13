#include <cstdio>

int main(){
	int n, m, a;
	scanf("%d %d %d", &n, &m, &a);
	int x;
	while(scanf("%d", &x) == 1){
		if(x == m / 2 + 1){
			printf("0");
			break;
		}
		a += x - (m / 2 + 1);
		if(a > n){
			a -= n;
		}
		if(a < 1){
			a += n;
		}
		printf("%d\n", a);
	}
	return 0;
}
