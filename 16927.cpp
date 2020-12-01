#include <cstdio>

void rotate_layer(int a[][300], int b[][300], int n, int m, int r, int i){
	r %= ((n - 2 * i) * (m - 2 * i) - (n - 2 * i - 2) * (m - 2 * i - 2));
	for(int a0 = 0; a0 < r; ++a0){
		for(int k = i; k < n - i - 1; ++k){
			b[k + 1][i] = a[k][i];
		}
		for(int k = i; k < m - i - 1; ++k){
			b[n - i - 1][k + 1] = a[n - i - 1][k];
		}
		for(int k = n - i - 1; k > i; --k){
			b[k - 1][m - i - 1] = a[k][m - i - 1];
		}
		for(int k = m - i - 1; k > i; --k){
			b[i][k - 1] = a[i][k];
		}
		for(int k = i; k < n - i - 1; ++k){
			a[k][i] = b[k][i];
		}
		for(int k = i; k < m - i - 1; ++k){
			a[n - i - 1][k] = b[n - i - 1][k];
		}
		for(int k = n - i - 1; k > i; --k){
			a[k][m - i - 1] = b[k][m - i - 1];
		}
		for(int k = m - i - 1; k > i; --k){
			a[i][k] = b[i][k];
		}
	}
}

void rotate(int a[][300], int n, int m, int r){
	int b[300][300] = {};
	for(int i = 0; i < n / 2 && i < m / 2; ++i){
		rotate_layer(a, b, n, m, r, i);
	}
}

int main(){
	int n, m, r;
	scanf("%d %d %d", &n, &m, &r);
	int a[300][300];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			scanf("%d", &a[i][j]);
		}
	}
	rotate(a, n, m, r);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
