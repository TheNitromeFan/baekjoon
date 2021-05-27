#include <iostream>
#define MOD 1000000LL

using namespace std;

long long f(long long n){
	long long ret = 0;
	for(long long i = 1, j = 0; i <= n; i = j + 1){
		j = n / (n / i);
		ret += (i + j) * (j - i + 1) / 2 * (n / i);
		ret %= MOD;
	}
	ret += MOD * MOD * MOD;
	ret -= n + n * (n + 1) / 2 - 1;
	ret %= MOD;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	cin >> n;
	cout << f(n);
	return 0;
}
