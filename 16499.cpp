#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	set<string> words;
	for(int i = 0; i < n; ++i){
		string word;
		cin >> word;
		sort(word.begin(), word.end());
		if(words.find(word) == words.end()){
			words.insert(word);
		}
	}
	cout << words.size();
	return 0;
}
