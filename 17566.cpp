#include <iostream>
#include <string>

using namespace std;

long long bitmask(string s){
	long long ret = 0;
	for(unsigned i = 0; i < s.length(); ++i){
		ret *= 2;
		ret += s[s.length() - 1 - i] - '0';
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unsigned m, b, s;
	cin >> m >> b >> s;
	long long bus = 1LL << (m - 1);
	long long ans = 0;
	for(unsigned i = 0; i < b; ++i){
		string line;
		cin >> line;
		long long bus1 = bitmask(line);
		if((bus & bus1) != 0){
			ans |= bus1;
		}
	}
	int bits = 0;
	while(ans > 0){
		bits += ans % 2;
		ans /= 2;
	}
	cout << (bits > 0 ? bits - 1 : 0);
	return 0;
}
