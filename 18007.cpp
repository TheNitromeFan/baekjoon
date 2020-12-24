#include <iostream>
#include <string>
#include <vector>
#define MOD 11092019

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	vector<int> cnt(26);
	for(char c : s){
		++cnt[c - 'a'];
	}
	long long ans = 1;
	for(int x : cnt){
		ans *= x + 1;
		ans %= MOD;
	}
	cout << ans;
	return 0;
}
