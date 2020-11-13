#include <iostream>
#include <string>

using namespace std;

bool valid(string &s, string &t, unsigned i){
	for(unsigned j = 0; j < t.length(); ++j){
		if(s[i + j] == t[j]){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s, t;
	cin >> s >> t;
	int cnt = 0;
	for(unsigned i = 0; i + t.length() <= s.length(); ++i){
		if(valid(s, t, i)){
			++cnt;
		}
	}
	cout << cnt;
	return 0;
}
