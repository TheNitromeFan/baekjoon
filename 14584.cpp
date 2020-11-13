#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool match(string &s, string &t, unsigned pos){
	for(unsigned idx = 0; idx < t.length(); ++idx){
		if(s[idx + pos] != t[idx]){
			return false;
		}
	}
	return true;
}

string rotate(string s, int key){
	string ret = s;
	for(char &c : ret){
		c -= key;
		if(c < 'a'){
			c += 26;
		}
	}
	return ret;
}

string caesar(vector<string> &words, string code){
	for(int key = 1; key <= 26; ++key){
		string ret = rotate(code, key);
		for(string word : words){
			if(ret.length() < word.length()){
				continue;
			}
			for(unsigned pos = 0; pos <= ret.length() - word.length(); ++pos){
				if(match(ret, word, pos)){
					return ret;
				}
			}
		}
	}
	return "Not Found";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string code;
	cin >> code;
	int n;
	cin >> n;
	vector<string> words(n, "");
	for(int i = 0; i < n; ++i){
		cin >> words[i];
	}
	cout << caesar(words, code);
	return 0;
}
