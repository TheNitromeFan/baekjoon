#include <cstdio>

long long combinations[30][30];

void calculate(){
	for(int i = 0; i <= 29; ++i){
		for(int j = 0; j <= i; ++j){
			if(i == 0 || j == 0){
				combinations[i][j] = 1;
			}else{
				combinations[i][j] = combinations[i-1][j-1] + combinations[i-1][j];
			}
		}
	}
}

int main(){
	calculate();
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	if(k == 0){
		k = 1;
	}
	int x = (k - 1) / m, y = (k - 1) % m;
	printf("%lld", combinations[x+y][x] * combinations[n-1-x+m-1-y][n-1-x]);
	return 0;
}
