#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin >> n;
	set<string> words;
	for(int i = 0; i < n; ++i){
		string word;
		cin >> word;
		words.insert(word);
		reverse(word.begin(), word.end());
		if(words.find(word) != words.end()){
			cout << word.length() << ' ' << word[word.length() / 2];
			break;
		}
	}
	return 0;
}
