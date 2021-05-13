#include <cstdio>
#define MAX 401

void shoot(char c[MAX][MAX], int m, int x, int y){
	for(int i = x; i < m; ++i){
		c[i][y] = '1' - c[i][y] + '0';
	}
	for(int j = 0; j <= y; ++j){
		c[x][j] = '1' - c[x][j] + '0';
	}
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int m, n;
		scanf("%d %d", &m, &n);
		char a[MAX][MAX];
		for(int i = 0; i < m; ++i){
			scanf("%s", a[i]);
		}
		int ans = 0;
		for(int i = 0; i < m; ++i){
			for(int j = n - 1; j >= 0; --j){
				if(a[i][j] == '0'){
					shoot(a, m, i, j);
					++ans;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
