#include <cstdio>
#include <vector>
#define MOD 100000007

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
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int k, n;
		scanf("%d %d", &k, &n);
		vector<long long> a((k + 1) * (k + 1), 0);
		if(k > 0){
			a[0] = 1;
			a[k] = 1;
			for(int i = 1; i <= k; ++i){
				a[(k + 2) * i - 1] = 1;
			}
		}else{
			a[0] = 2;
		}
		vector<long long> mat = power(a, k + 1, n);
		long long ans = 0;
		for(int i = 0; i <= k; ++i){
			ans += mat[k * (k + 1) + i];
			ans %= MOD;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
