#include <iostream>
#define MAX 100

using namespace std;

void copy_matrix(long long src[][MAX], long long dest[][MAX], int n){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			dest[i][j] = src[i][j];
		}
	}
}

void multiply(long long a[][MAX], long long b[][MAX], long long c[][MAX], int n, long long m){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			c[i][j] = 0;
			for(int k = 0; k < n; ++k){
				c[i][j] += a[i][k] * b[k][j];
				c[i][j] %= m;
			}
		}
	}
}

void power(long long a[][MAX], long long res[][MAX], int n, long long m, int p){
	if(p == 1){
		copy_matrix(a, res, n);
	}else if(p % 2 == 0){
		long long b[MAX][MAX];
		multiply(a, a, b, n, m);
		power(b, res, n, m, p / 2);
	}else{
		long long b[MAX][MAX], c[MAX][MAX];
		multiply(a, a, b, n, m);
		power(b, c, n, m, p / 2);
		multiply(a, c, res, n, m);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n;
		long long m;
		int p;
		cin >> n >> m >> p;
		if(n == 0 && m == 0 && p == 0){
			break;
		}
		long long a[MAX][MAX];
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				cin >> a[i][j];
			}
		}
		long long ans[MAX][MAX];
		power(a, ans, n, m, p);
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				cout << ans[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
	return 0;
}
