#include <iostream>
#include <string>

using namespace std;

bool good_folding(string s){
	unsigned n = s.length();
	if(n == 1){
		return true;
	}
	for(unsigned i = 0; i < n / 2; ++i){
		if(s[i] == s[n - 1 - i]){
			return false;
		}
	}
	return good_folding(s.substr(0, n / 2));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		string pattern;
		cin >> pattern;
		cout << (good_folding(pattern) ? "YES" : "NO") << '\n';
	}
	return 0;
}
