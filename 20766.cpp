#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	string s;
	getline(cin, s);
	for(int a0 = 0; a0 < t; ++a0){
		getline(cin, s);
		string::size_type len = s.length();
		string ans;
		for(string::size_type i = 0; i < len; ++i){
			if(s[i] == ':' || s[i] == '-'){
				if(i != 0 && s[i - 1] != ' ' && s[i - 1] != ':' && s[i - 1] != '-'){
					ans += ' ';
				}
				ans += s[i];
				if(i + 1 != len && s[i + 1] != ' '){
					ans += ' ';
				}
			}else{
				ans += s[i];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
