#include <cstdio>
#define MAX (1000 + 1)

bool happy(int x[][MAX], int n, int a, int b){
	for(int j = 1; j <= n; ++j){
		if(x[a][b] < x[a][j]){
			return false;
		}
	}
	for(int i = 1; i <= n; ++i){
		if(x[a][b] < x[i][b]){
			return false;
		}
	}
	return true;
}

int main(){
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);
	static int x[MAX][MAX];
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			scanf("%d", &x[i][j]);
		}
	}
	printf("%s", happy(x, n, a, b) ? "HAPPY" : "ANGRY");
	return 0;
}
