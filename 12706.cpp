#include <cstdio>

void triangle(int n, int m, int a){
	if(n * m < a){
		printf("IMPOSSIBLE");
		return;
	}
	if(n <= m){
		for(int i = 0; i < m; ++i){
			if((a + i) % n == 0){
				printf("0 0 1 %d %d %d", (a + i) / n, n, i);
				return;
			}
		}
	}else{
		for(int i = 0; i < n; ++i){
			if((a + i) % m == 0){
				printf("0 0 %d 1 %d %d", (a + i) / m, i, m);
				return;
			}
		}
	}
}

int main(){
	int c;
	scanf("%d", &c);
	for(int a0 = 1; a0 <= c; ++a0){
		int n, m, a;
		scanf("%d %d %d", &n, &m, &a);
		printf("Case #%d: ", a0);
		triangle(n, m, a);
		printf("\n");
	}
	return 0;
}
