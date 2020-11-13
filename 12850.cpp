#include <cstdio>
#include <vector>
#define MOD 1000000007
#define SIZE 8

using std::vector;

vector<long long> multiply(vector<long long> a, vector<long long> b){
	vector<long long> ret(SIZE * SIZE, 0);
	for(int i = 0; i < SIZE; ++i){
		for(int j = 0; j < SIZE; ++j){
			for(int k = 0; k < SIZE; ++k){
				ret[i * SIZE + j] += a[i * SIZE + k] * b[k * SIZE + j];
				ret[i * SIZE + j] %= MOD;
			}
		}
	}
	return ret;
}

vector<long long> power(vector<long long> a, int exp){
	vector<long long> ret(SIZE * SIZE, 0);
	if(exp == 0){
		for(int i = 0; i < SIZE; ++i){
			ret[i * SIZE + i] = 1;
		}
	}else if(exp % 2 == 0){
		vector<long long> tmp = power(a, exp / 2);
		ret = multiply(tmp, tmp);
	}else{
		vector<long long> tmp = power(a, exp / 2);
		ret = multiply(multiply(tmp, tmp), a);
	}
	return ret;
}

int main(){
	int d;
	scanf("%d", &d);
	vector<long long> a(SIZE * SIZE, 0);
	a[0 * SIZE + 1] = 1;
	a[1 * SIZE + 0] = 1;
	a[0 * SIZE + 2] = 1;
	a[2 * SIZE + 0] = 1;
	a[1 * SIZE + 2] = 1;
	a[2 * SIZE + 1] = 1;
	a[1 * SIZE + 3] = 1;
	a[3 * SIZE + 1] = 1;
	a[2 * SIZE + 3] = 1;
	a[3 * SIZE + 2] = 1;
	a[2 * SIZE + 4] = 1;
	a[4 * SIZE + 2] = 1;
	a[3 * SIZE + 4] = 1;
	a[4 * SIZE + 3] = 1;
	a[3 * SIZE + 5] = 1;
	a[5 * SIZE + 3] = 1;
	a[4 * SIZE + 5] = 1;
	a[5 * SIZE + 4] = 1;
	a[4 * SIZE + 6] = 1;
	a[6 * SIZE + 4] = 1;
	a[5 * SIZE + 7] = 1;
	a[7 * SIZE + 5] = 1;
	a[6 * SIZE + 7] = 1;
	a[7 * SIZE + 6] = 1;
	vector<long long> mat = power(a, d);
	printf("%lld", mat[0]);
	return 0;
}
