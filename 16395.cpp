#include <cstdio>
#define MAX 30

int main(){
	long long c[MAX][MAX] = {1};
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 1; i < n; ++i){
		for(int j = 0; j <= i; ++j){
			if(j == 0 || j == i){
				c[i][j] = 1;
			}else{
				c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			}
		}
	}
	printf("%lld", c[n - 1][k - 1]);
	return 0;
}
