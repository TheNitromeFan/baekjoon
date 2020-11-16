#include <cstdio>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char paint[1000][1000];
	for(int i = 0; i < n; ++i){
		scanf("%s", paint[i]);
	}
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			printf("%c", paint[n - j - 1][i]);
		}
		printf("\n");
	}
	return 0;
}
