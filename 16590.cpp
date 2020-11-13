#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool acronym(vector<string> &v, vector<bool> &b, string &s, unsigned idx){
	if(idx == s.length()){
		return true;
	}
	for(unsigned i = 0; i < v.size(); ++i){
		if(b[i]){
			continue;
		}
		for(char c : v[i]){
			if(c == s[idx]){
				b[i] = true;
				if(acronym(v, b, s, idx + 1)){
					return true;
				}
				b[i] = false;
				break;
			}
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	string line;
	getline(cin, line);
	vector<string> initials(n, "");
	for(int i = 0; i < n; ++i){
		getline(cin, line);
		string capitals;
		for(char c : line){
			if(c >= 'A' && c <= 'Z'){
				capitals += c;
			}
		}
		initials[i] = capitals;
	}
	for(int j = 0; j < q; ++j){
		string query;
		cin >> query;
		vector<bool> selected(n, false);
		if(acronym(initials, selected, query, 0)){
			cout << "YES";
		}else{
			cout << "NO";
		}
		cout << '\n';
	}
	return 0;
}
