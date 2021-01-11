#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> prime_powers(int n){
	vector<long long> ret;
	for(int p = 2; p * p <= n; ++p){
		int cnt = 0;
		while(n % p == 0){
			++cnt;
			n /= p;
		}
		long long q = p;
		while(cnt > 0){
			if(cnt % 2 == 1){
				ret.push_back(q);
			}
			q = q * q;
			cnt /= 2;
		}
	}
	if(n > 1){
		ret.push_back(n);
	}
	sort(ret.begin(), ret.end());
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int n;
		cin >> n;
		vector<long long> ans = prime_powers(n);
		for(long long x : ans){
			cout << x << ' ';
		}
		cout << '\n';
	}
	return 0;
}
