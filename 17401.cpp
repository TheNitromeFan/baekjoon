#include <iostream>
#define MOD 1000000007

using namespace std;

void fill_identity(long long a[][21], int n){
	for(int i = 1; i <= n; ++i){
		a[i][i] = 1;
	}
}

void copy_array(long long src[][21], long long dest[][21], int n){
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			dest[i][j] = src[i][j];
		}
	}
}

void multiply(long long a[][21], long long b[][21], long long c[][21], int n){
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			c[i][j] = 0;
			for(int k = 1; k <= n; ++k){
				c[i][j] += a[i][k] * b[k][j];
				c[i][j] %= MOD;
			}
		}
	}
}

void power(long long a[][21], long long b[][21], int n, int k){
	if(k == 0){
		fill_identity(b, n);
		return;
	}else if(k % 2 == 0){
		long long tmp[21][21] = {};
		fill_identity(tmp, n);
		multiply(a, a, tmp, n);
		power(tmp, b, n, k / 2);
	}else{
		long long tmp1[21][21] = {}, tmp2[21][21] = {};
		fill_identity(tmp1, n);
		fill_identity(tmp2, n);
		multiply(a, a, tmp1, n);
		power(tmp1, tmp2, n, k / 2);
		multiply(tmp2, a, b, n);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, d;
	cin >> t >> n >> d;
	long long map[101][21][21] = {};
	for(int i = 1; i <= t; ++i){
		int m;
		cin >> m;
		for(int a0 = 0; a0 < m; ++a0){
			int a, b;
			long long c;
			cin >> a >> b >> c;
			map[i][a][b] = c;
		}
	}
	int q = d / t, r = d % t;
	long long quot[21][21] = {}, rem[21][21] = {}, tmp[21][21] = {}, ans[21][21] = {};
	fill_identity(quot, n);
	fill_identity(rem, n);
	fill_identity(tmp, n);
	for(int i = 1; i <= t; ++i){
		if(i == r + 1){
			copy_array(tmp, rem, n);
		}
		multiply(quot, map[i], tmp, n);
		copy_array(tmp, quot, n);
	}
	/*
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			cout << quot[i][j];
		}
		cout << '\n';
	}
	*/
	fill_identity(tmp, n);
	power(quot, tmp, n, q);
	multiply(tmp, rem, ans, n);
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
