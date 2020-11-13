#include <cstdio>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int c[41] = {};
	int max = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			++c[i + j];
			if(c[i + j] > max){
				max = c[i + j];
			}
		}
	}
	for(int k = 0; k < 41; ++k){
		if(c[k] == max){
			printf("%d\n", k);
		}
	}
	return 0;
}
