#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool is_similar(string &s, string &t){
	map<char, char> m, n;
	for(unsigned i = 0; i < s.length(); ++i){
		if(m.find(s[i]) == m.end()){
			m[s[i]] = t[i];
		}else if(m[s[i]] != t[i]){
			return false;
		}
		if(n.find(t[i]) == n.end()){
			n[t[i]] = s[i];
		}else if(n[t[i]] != s[i]){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unsigned n;
	cin >> n;
	vector<string> words(n, "");
	for(unsigned i = 0; i < n; ++i){
		cin >> words[i];
	}
	int ans = 0;
	for(unsigned i = 0; i < n; ++i){
		for(unsigned j = 0; j < i; ++j){
			if(is_similar(words[j], words[i])){
				++ans;
			}
		}
	}
	cout << ans;
	return 0;
}
