#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool correct_adj(string &s, string &t){
	if(s.length() != t.length()){
		return false;
	}
	int changed = 0;
	for(unsigned idx = 0; idx < s.length(); ++idx){
		if(s[idx] != t[idx]){
			++changed;
		}
	}
	return changed == 1;
}

bool correct_ladder(vector<string> &words){
	for(unsigned idx = 0; idx + 1 < words.size(); ++idx){
		if(!correct_adj(words[idx], words[idx + 1])){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		vector<string> words;
		while(true){
			string word;
			cin >> word;
			if(word == "#"){
				break;
			}
			words.push_back(word);
		}
		if(words.empty()){
			break;
		}
		cout << (correct_ladder(words) ? "Correct" : "Incorrect") << '\n';
	}
	return 0;
}
