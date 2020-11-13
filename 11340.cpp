#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int p, t, m;
		scanf("%d %d %d", &p, &t, &m);
		int num = 1800 - 3 * p - 4 * t - 5 * m;
		int f = (num % 8 == 0) ? num / 8 : num / 8 + 1;
		if(f <= 100){
			printf("%d", f);
		}else{
			printf("impossible");
		}
		printf("\n");
	}
	return 0;
}
