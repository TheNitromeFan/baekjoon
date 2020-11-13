#include <iostream>
#include <string>

using namespace std;

bool match(string str, string pat){
	if(str.length() + 1 < pat.length()){
		return false;
	}
	for(unsigned i = 0; pat[i] != '*'; ++i){
		if(str[i] != pat[i]){
			return false;
		}
	}
	for(unsigned j = 0; pat[pat.length() - 1 - j] != '*'; ++j){
		if(str[str.length() - 1 - j] != pat[pat.length() - 1 - j]){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	string pattern;
	cin >> pattern;
	for(int i = 0; i < n; ++i){
		string s;
		cin >> s;
		if(match(s, pattern)){
			cout << "DA";
		}else{
			cout << "NE";
		}
		cout << '\n';
	}
	return 0;
}
