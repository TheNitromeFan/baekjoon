#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_prefix(string short_word, string long_word){
	for(unsigned i = 0; i < short_word.length(); ++i){
		if(short_word[i] != long_word[i]){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<string> words(n, "");
	for(int i = 0; i < n; ++i){
		cin >> words[i];
	}
	sort(words.begin(), words.end());
	int ans = n;
	for(int i = 0; i < n - 1; ++i){
		if(is_prefix(words[i], words[i + 1])){
			--ans;
		}
	}
	cout << ans;
	return 0;
}
