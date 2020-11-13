#include <cstdio>
#include <vector>
#define MOD 100

using std::vector;

vector<int> multiply(vector<int> a, vector<int> b){
	vector<int> ret(4, 0);
	ret[0] = (a[0] * b[0] + a[1] * b[2]) % MOD;
	ret[1] = (a[0] * b[1] + a[1] * b[3]) % MOD;
	ret[2] = (a[2] * b[0] + a[3] * b[2]) % MOD;
	ret[3] = (a[2] * b[1] + a[3] * b[3]) % MOD;
	return ret;
}

vector<int> power(vector<int> a, int exp){
	vector<int> ret = {1, 0, 0, 1};
	if(exp == 0);
	else if(exp % 2 == 0){
		vector<int> tmp = power(a, exp / 2);
		ret = multiply(tmp, tmp);
	}else{
		vector<int> tmp = power(a, exp / 2);
		ret = multiply(multiply(tmp, tmp), a);
	}
	return ret;
}

int main(){
	int x, y, a0, a1, n;
	scanf("%d %d %d %d %d", &x, &y, &a0, &a1, &n);
	vector<int> a = {x, y, 1, 0};
	vector<int> mat = power(a, n);
	printf("%02d", (mat[2] * a1 + mat[3] * a0) % MOD);
	return 0;
}
