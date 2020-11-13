#include <cstdio>

int to_print[9];

void backtrack(int n, int m, int len){
	if(len == m){
		for(int i = 0; i < m; ++i){
			printf("%d ", to_print[i]);
		}
		printf("\n");
		return;
	}
	for(int i = 1; i <= n; ++i){
		to_print[len] = i;
		backtrack(n, m, len+1);
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	backtrack(n, m, 0);
	return 0;
}
