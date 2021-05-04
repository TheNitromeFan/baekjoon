#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unordered_map<string, int> occur;
	unsigned n, m;
	cin >> n >> m;
	vector<string> words;
	for(unsigned i = 0; i < n; ++i){
		string word;
		cin >> word;
		if(word.length() < m){
			continue;
		}
		if(occur[word] == 0){
			words.push_back(word);
		}
		++occur[word];
	}
	sort(words.begin(), words.end(), [&occur](string a, string b){
		return occur[a] > occur[b] ||
		(occur[a] == occur[b] && (a.length() > b.length() ||
		(a.length() == b.length() && a < b)));
	});
	for(string &word : words){
		cout << word << "\n";
	}
	return 0;
}
