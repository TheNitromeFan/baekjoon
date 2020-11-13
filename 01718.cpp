#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s, key;
	getline(cin, s);
	getline(cin, key);
	string ans = "";
	for(unsigned i = 0; i < s.length(); ++i){
		if(s[i] == ' '){
			ans += ' ';
			continue;
		}
		char tmp = s[i] - key[i % key.length()] - 1 + 'a';
		if(tmp < 'a'){
			tmp += 26;
		}
		ans += tmp;
	}
	cout << ans;
	return 0;
}
