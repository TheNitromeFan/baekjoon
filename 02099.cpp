#include <cstdio>
#include <vector>

using std::vector;

vector<bool> multiply(vector<bool> a, vector<bool> b, int sz){
	vector<bool> ret(sz * sz, false);
	for(int i = 0; i < sz; ++i){
		for(int j = 0; j < sz; ++j){
			for(int k = 0; k < sz; ++k){
				if(a[i * sz + k] && b[k * sz + j]){
					ret[i * sz + j] = true;
				}
			}
		}
	}
	return ret;
}

vector<bool> power(vector<bool> a, int sz, int exp){
	vector<bool> ret(sz * sz, false);
	if(exp == 0){
		for(int i = 0; i < sz; ++i){
			ret[i * sz + i] = true;
		}
	}else if(exp % 2 == 0){
		vector<bool> tmp = power(a, sz, exp / 2);
		ret = multiply(tmp, tmp, sz);
	}else{
		vector<bool> tmp = power(a, sz, exp / 2);
		ret = multiply(multiply(tmp, tmp, sz), a, sz);
	}
	return ret;
}

int main(){
	int n, k, m;
	scanf("%d %d %d", &n, &k, &m);
	vector<bool> a(n * n, false);
	for(int i = 0; i < n; ++i){
		int x, y;
		scanf("%d %d", &x, &y);
		--x;
		--y;
		a[i * n + x] = true;
		a[i * n + y] = true;
	}
	vector<bool> mat = power(a, n, k);
	/*
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			printf("%s ", mat[i * n + j] ? "true" : "false");
		}
		printf("\n");
	}
	*/
	for(int j = 0; j < m; ++j){
		int x, y;
		scanf("%d %d", &x, &y);
		--x;
		--y;
		printf("%s\n", mat[x * n + y] ? "death" : "life");
	}
	return 0;
}
