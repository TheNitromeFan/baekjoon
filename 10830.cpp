#include <iostream>
#include <vector>
#define MOD 1000

using namespace std;

vector<int> product(vector<int> a, vector<int> b, int sz){
	vector<int> c;
	for(int i = 0; i < sz; ++i){
		for(int j = 0; j < sz; ++j){
			int elem = 0;
			for(int k = 0; k < sz; ++k){
				elem += a[i*sz+k] * b[k*sz+j];
				elem %= MOD;
			}
			c.push_back(elem);
		}
	}
	return c;
}

vector<int> power(vector<int> a, int sz, long long exp){
	if(exp == 1LL){
		return a;
	}else if(exp % 2 == 0LL){
		return power(product(a, a, sz), sz, exp / 2);
	}else{
		return product(power(product(a, a, sz), sz, exp / 2), a, sz);
	}
}


int main(){
	int n;
	long long b;
	cin >> n >> b;
	vector<int> a;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			int x;
			cin >> x;
			a.push_back(x % MOD);
		}
	}
	vector<int> c = power(a, n, b);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cout << c[i*n + j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
