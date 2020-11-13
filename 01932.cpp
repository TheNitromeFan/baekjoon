#include <cstdio>

static int maximum(int a, int b){
	if(a > b){
		return a;
	}else{
		return b;
	}
}

int main(){
	static int a[501][501], max[501][501];
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= i; ++j){
			scanf("%d", &a[i][j]);
		}
	}
	max[1][1] = a[1][1];
	for(int i = 2; i <= n; ++i){
		for(int j = 1; j <= i; ++j){
			if(j == 1){
				max[i][j] = max[i-1][j] + a[i][j]; 
			}else if(j == i){
				max[i][j] = max[i-1][j-1] + a[i][j];
			}else{
				max[i][j] = maximum(max[i-1][j-1], max[i-1][j]) + a[i][j];
			}
		}
	}
	int answer = 0;
	for(int j = 1; j <= n; ++j){
		if(answer < max[n][j]){
			answer = max[n][j];
		}
	}
	printf("%d", answer);
	return 0;
}
