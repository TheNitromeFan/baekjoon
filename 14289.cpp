#include <cstdio>
#include <vector>
#define MOD 1000000007

using std::vector;

vector<long long> multiply(vector<long long> a, vector<long long> b, int sz){
	vector<long long> ret(sz * sz, 0);
	for(int i = 0; i < sz; ++i){
		for(int j = 0; j < sz; ++j){
			for(int k = 0; k < sz; ++k){
				ret[i * sz + j] += a[i * sz + k] * b[k * sz + j];
				ret[i * sz + j] %= MOD;
			}
		}
	}
	return ret;
}

vector<long long> power(vector<long long> a, int sz, int exp){
	vector<long long> ret(sz * sz, 0);
	if(exp == 0){
		for(int i = 0; i < sz; ++i){
			ret[i * sz + i] = 1;
		}
	}else if(exp % 2 == 0){
		vector<long long> tmp = power(a, sz, exp / 2);
		ret = multiply(tmp, tmp, sz);
	}else{
		vector<long long> tmp = power(a, sz, exp / 2);
		ret = multiply(multiply(tmp, tmp, sz), a, sz);
	}
	return ret;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<long long> a(n * n, 0);
	for(int i = 0; i < m; ++i){
		int x, y;
		scanf("%d %d", &x, &y);
		--x;
		--y;
		a[x * n + y] = 1;
		a[y * n + x] = 1;
	}
	int d;
	scanf("%d", &d);
	vector<long long> mat = power(a, n, d);
	printf("%lld", mat[0]);
	return 0;
}
