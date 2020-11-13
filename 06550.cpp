#include <iostream>
#include <string>

using namespace std;

bool subseq(string &s, string &t){
	unsigned idx = 0;
	for(unsigned i = 0; i < t.length(); ++i){
		if(s[idx] == t[i]){
			++idx;
			if(idx == s.length()){
				return true;
			}
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s, t;
	while(cin >> s >> t){
		cout << (subseq(s, t) ? "Yes" : "No") << '\n';
	}
	return 0;
}
