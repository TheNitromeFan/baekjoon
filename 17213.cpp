#include <cstdio>
#define MAX 30

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	long long c[MAX][MAX] = {};
	c[0][0] = 1;
	for(int i = 0; i < m; ++i){
		for(int j = 0; j <= i; ++j){
			if(j == 0 || j == i){
				c[i][j] = 1;
			}else{
				c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			}
		}
	}
	printf("%lld", c[m - 1][m - n]);
	return 0;
}
