#include <iostream>

using namespace std;

long long power(long long x, int n){
	long long ret = 1;
	for(int i = 0; i < n; ++i){
		ret *= x;
	}
	return ret;
}

long long f(long long n, int k){
	if(n == 0){
		return 0;
	}
	long long ret = 0;
	for(long long i = 1, j = 0; i <= n; i = j + 1){
		j = n / (n / i);
		ret += (j - i + 1) * (n / i);
	}
	for(long long i = 1, p = 1; p <= n; ++i, p = power(i, k)){
		ret -= n / p;
	}
	ret -= n - 1;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long a, b, n;
	cin >> a >> b >> n;
	cout << f(a + b, n) - f(a - 1, n);
	return 0;
}
