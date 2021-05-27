#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<long long> x(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> x[i];
	}
	if(n == 1){
		cout << x[1];
		return 0;
	}
	long long ans = min(x[1], x[2]) * min(x[n - 1], x[n]) % MOD;
	for(int i = 2; i < n; ++i){
		ans *= min(min(x[i - 1], x[i]), x[i + 1]);
		ans %= MOD;
	}
	cout << ans;
	return 0;
}
