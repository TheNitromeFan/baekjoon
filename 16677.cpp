#include <iostream>
#include <string>

using namespace std;

bool match(string &s, string &t){
	unsigned i = 0;
	for(unsigned j = 0; j < t.length(); ++j){
		if(t[j] == s[i]){
			++i;
			if(i == s.length()){
				return true;
			}
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string m;
	int n;
	cin >> m >> n;
	string ans_str = "No Jam";
	unsigned ans_num = 0, ans_den = 1;
	for(int i = 0; i < n; ++i){
		string w;
		unsigned g;
		cin >> w >> g;
		if(!match(m, w)){
			continue;
		}
		unsigned len = w.length() - m.length();
		if(g * ans_den > len * ans_num){
			ans_str = w;
			ans_num = g;
			ans_den = len;
		}
	}
	cout << ans_str;
	return 0;
}
