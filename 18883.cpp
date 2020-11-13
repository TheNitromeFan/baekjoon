#include <cstdio>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			printf("%d", m * i + j + 1);
			if(j < m - 1){
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
