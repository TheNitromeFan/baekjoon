#include <iostream>
#include <string>
#define MAX 60
#define MOD 1000003

using namespace std;

void copy_matrix(long long src[][MAX], long long dest[][MAX], int n){
	for(int i = 0; i < 5 * n; ++i){
		for(int j = 0; j < 5 * n; ++j){
			dest[i][j] = src[i][j];
		}
	}
}

void prod(long long a[][MAX], long long b[][MAX], long long c[][MAX], int n){
	for(int i = 0; i < 5 * n; ++i){
		for(int j = 0; j < 5 * n; ++j){
			for(int k = 0; k < 5 * n; ++k){
				c[i][j] += a[i][k] * b[k][j];
				c[i][j] %= MOD;
			}
		}
	}
}

void power(long long a[][MAX], long long b[][MAX], int n, int exp){
	if(exp == 1){
		copy_matrix(a, b, n);
		return;
	}else if(exp % 2 == 0){
		long long c[MAX][MAX] = {};
		prod(a, a, c, n);
		power(c, b, n, exp / 2);
	}else{
		long long c[MAX][MAX] = {}, d[MAX][MAX] = {};
		prod(a, a, c, n);
		power(c, d, n, exp / 2);
		prod(a, d, b, n);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, s, e, t;
	cin >> n >> s >> e >> t;
	long long a[MAX][MAX] = {};
	for(int i = 0; i < 5 * n; i += 5){
		for(int j = 1; j < 5; ++j){
			a[i + j][i + j - 1] = 1;
		}
	}
	for(int i = 0; i < 5 * n; i += 5){
		string line;
		cin >> line;
		for(int j = 0; j < n; ++j){
			int time = line[j] - '0';
			if(time > 0){
				a[i][5 * j + time - 1] = 1;
			}
		}
	}
	long long b[MAX][MAX] = {};
	power(a, b, n, t);
	cout << b[5 * (s - 1)][5 * (e - 1)];
	return 0;
}
