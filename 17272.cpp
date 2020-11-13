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

vector<long long> power(vector<long long> a, int sz, long long exp){
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
	long long n;
	int m;
	scanf("%lld %d", &n, &m);
	vector<long long> a(m * m, 0);
	a[0] = 1;
	a[m - 1] = 1;
	for(int i = 1; i < m; ++i){
		a[i * m + i - 1] = 1;
	}
	vector<long long> mat = power(a, m, n - 1);
	long long ans = mat[(m - 1) * m];
	for(int i = 0; i < m; ++i){
		ans += mat[(m - 1) * m + i];
		ans %= MOD;
	}
	printf("%lld\n", ans);
	return 0;
}
