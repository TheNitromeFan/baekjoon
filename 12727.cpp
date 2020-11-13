#include <cstdio>
#include <vector>
#define MOD 1000

using namespace std;

vector<int> multiply(vector<int> a, vector<int> b){
	vector<int> ret(4, 0);
	ret[0] = (a[0] * b[0] + a[1] * b[2]) % MOD;
	ret[1] = (a[0] * b[1] + a[1] * b[3]) % MOD;
	ret[2] = (a[2] * b[0] + a[3] * b[2]) % MOD;
	ret[3] = (a[2] * b[1] + a[3] * b[3]) % MOD;
	return ret;
}

vector<int> power(vector<int> &a, int n){
	vector<int> ret = {1, 0, 0, 1};
	if(n == 0){
		return ret;
	}else if(n % 2){
		ret = power(a, n / 2);
		return multiply(multiply(ret, ret), a);
	}else{
		ret = power(a, n / 2);
		return multiply(ret, ret);
	}
	return ret;
}

int main(){
	vector<int> a = {3, 5, 1, 3};
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; ++i){
		int n;
		scanf("%d", &n);
		vector<int> ans = power(a, n);
		printf("Case #%d: %03d\n", i, (2 * ans[0] + MOD - 1) % MOD);
	}
	return 0;
}
