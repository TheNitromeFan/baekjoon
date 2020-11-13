#include <iostream>
#include <string>

using namespace std;

bool match(string s, string t, unsigned pos){
	for(unsigned i = 0; i < t.length(); ++i){
		if(s[i + pos] != t[i]){
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
	for(unsigned pos = 0; pos <= s.length() - t.length(); ++pos){
		if(match(s, t, pos)){
			++cnt;
		}
	}
	cout << cnt;
	return 0;
}
