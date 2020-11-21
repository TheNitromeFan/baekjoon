#include <cstdio>
#define MOD 1000000007

bool mult(long long a[][51], long long b[][51], int &m, int &n, int &m1, int &n1){
	if(n != m1){
		return false;
	}
	long long c[51][51];
	for(int i = 1; i <= m; ++i){
		for(int j = 1; j <= n1; ++j){
			c[i][j] = 0;
			for(int k = 1; k <= n; ++k){
				c[i][j] += a[i][k] * b[k][j];
				c[i][j] %= MOD;
			}
		}
	}
	n = n1;
	for(int i = 1; i <= m; ++i){
		for(int j = 1; j <= n; ++j){
			a[i][j] = c[i][j];
		}
	}
	return true;
}

bool prod(long long a[][51], int n, int &x, int &y){
	for(int i = 1; i <= x; ++i){
		for(int j = 1; j <= y; ++j){
			scanf("%lld", &a[i][j]);
		}
	}
	long long b[51][51];
	for(int a0 = 1; a0 < n; ++a0){
		int z, w;
		scanf("%d %d", &z, &w);
		for(int i = 1; i <= z; ++i){
			for(int j = 1; j <= w; ++j){
				scanf("%lld", &b[i][j]);
			}
		}
		if(!mult(a, b, x, y, z, w)){
			return false;
		}
	}
	return true;
}

int main(){
	int n;
	scanf("%d", &n);
	long long a[51][51];
	int x, y;
	scanf("%d %d", &x, &y);
	if(prod(a, n, x, y)){
		int sum = 0;
		for(int i = 1; i <= x; ++i){
			for(int j = 1; j <= y; ++j){
				sum += a[i][j];
				sum %= MOD;
			}
		}
		printf("%d", sum);
	}else{
		printf("-1");
	}
	return 0;
}
