#include <iostream>
#include <vector>

using namespace std;

void prime_factorize(vector<long long> &v, long long n){
	for(long long p = 2; p * p <= n; ++p){
		while(n % p == 0){
			v.push_back(p);
			n /= p;
		}
	}
	if(n > 1){
		v.push_back(n);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long k;
	cin >> k;
	vector<long long> ans;
	prime_factorize(ans, k);
	cout << ans.size() << '\n';
	for(long long p : ans){
		cout << p << ' ';
	}
	return 0;
}
