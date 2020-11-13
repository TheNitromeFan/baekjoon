#include <iostream>
#include <string>

using namespace std;

bool match(string &s, string &t, unsigned pos){
	if(pos + t.length() > s.length()){
		return false;
	}
	for(unsigned idx = 0; idx < t.length(); ++idx){
		if(s[idx + pos] != t[idx]){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		string s, p;
		cin >> s >> p;
		unsigned idx = 0;
		int ans = 0;
		while(idx < s.length()){
			if(match(s, p, idx)){
				idx += p.length();
			}else{
				++idx;
			}
			++ans;
		}
		cout << ans << '\n';
	}
	return 0;
}
