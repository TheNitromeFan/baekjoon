#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool forms_cycle(string s, unsigned len){
	if(s.length() % len != 0){
		return false;
	}
	for(unsigned i = 0; i < s.length(); ++i){
		if(s[i] != s[i % len]){
			return false;
		}
	}
	return true;
}

string shortest_cycle(string s){
	for(unsigned len = 1; len <= s.length() / 2; ++len){
		if(forms_cycle(s, len)){
			return s.substr(0, len);
		}
	}
	return s;
}

vector<string> pattern(string word){
	vector<string> ret(2, "");
	if(word.length() % 2 == 1){
		word = word + word;
	}
	for(unsigned i = 0; i < word.length(); ++i){
		ret[i % 2] += word[i];
	}
	ret[0] = shortest_cycle(ret[0]);
	ret[1] = shortest_cycle(ret[1]);
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		string s;
		cin >> s;
		auto ans = pattern(s);
		cout << ans[0] << '\n' << ans[1] << '\n';
	}
	return 0;
}
