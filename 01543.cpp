#include <iostream>
#include <string>

using namespace std;

bool match(string s, string t, unsigned x){
	if(x + t.length() > s.length()){
		return false;
	}
	for(unsigned i = 0; i < t.length(); ++i){
		if(s[x + i] != t[i]){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s, t;
	getline(cin, s);
	getline(cin, t);
	unsigned idx = 0;
	int ans = 0;
	while(idx < s.length()){
		if(match(s, t, idx)){
			idx += t.length();
			++ans;
		}else{
			++idx;
		}
	}
	cout << ans;
	return 0;
}
