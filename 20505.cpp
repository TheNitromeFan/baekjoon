#include <iostream>
#include <string>
#include <algorithm>
#define MAX 250003
#define MOD 998244353

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long powers_of_11[MAX] = {1}, powers_of_2[MAX] = {1};
	for(unsigned i = 1; i < MAX; ++i){
		powers_of_11[i] = powers_of_11[i - 1] * 11 % MOD;
		powers_of_2[i] = powers_of_2[i - 1] * 2 % MOD;
	}
	string n;
	cin >> n;
	unsigned len = n.length();
	long long ans = 0;
	for(unsigned i = 0; i < len; ++i){
		int ai = n[i] - '0';
		ans += ai * powers_of_11[len - 1 - i] % MOD * powers_of_2[i] % MOD;
		ans %= MOD;
	}
	cout << ans;
	return 0;
}
