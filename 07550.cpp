#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#define MAX 100000

using namespace std;

void parse(string &line, vector<string> &words){
	string word;
	for(char c : line){
		if(c >= 'a' && c <= 'z'){
			word += c;
		}else if(c >= 'A' && c <= 'Z'){
			word += (char)(c - 'A' + 'a');
		}else{
			if(!word.empty()){
				words.push_back(word);
			}
			word = "";
		}
	}
	if(!word.empty()){
		words.push_back(word);
	}
}

unsigned final_word(unsigned dest[MAX], vector<string> &words, unsigned thres, unsigned idx){
	if(idx >= thres && idx < words.size()){
		return idx;
	}else if(idx >= words.size()){
		return 0;
	}else if(dest[idx]){
		return dest[idx];
	}
	dest[idx] = final_word(dest, words, thres, idx + words[idx].length());
	return dest[idx];
}

vector<string> magic_trick(vector<string> &words1, vector<string> &words2, vector<string> &words3){
	set<unsigned> ans;
	unsigned dest[MAX] = {};
	vector<string> words;
	for(string &word : words1){
		words.push_back(word);
	}
	for(string &word : words2){
		words.push_back(word);
	}
	for(string &word : words3){
		words.push_back(word);
	}
	unsigned thres = words1.size() + words2.size();
	vector<string> ret;
	for(unsigned idx = 0; idx < words1.size(); ++idx){
		ans.insert(final_word(dest, words, thres, idx));
		if(ans.size() > 3){
			ret.push_back("-too many-");
			return ret;
		}
	}
	for(unsigned a : ans){
		if(a == 0){
			ret.push_back("-outside-");
		}else{
			ret.push_back(words[a]);
		}
	}
	sort(ret.begin(), ret.end());
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	string line;
	getline(cin, line);
	for(int a0 = 1; a0 <= t; ++a0){
		vector<string> words1, words2, words3;
		getline(cin, line);
		parse(line, words1);
		getline(cin, line);
		parse(line, words2);
		getline(cin, line);
		parse(line, words3);
		cout << "Scenario #" << a0 << ":\n";
		vector<string> ans = magic_trick(words1, words2, words3);
		for(string s : ans){
			cout << s << "\n";
		}
		cout << "\n";
	}
	return 0;
}
