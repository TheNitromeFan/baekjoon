#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool is_palindrome(string &s, unsigned i, unsigned j){
	while(i < j){
		if(s[i] != s[j]){
			return false;
		}
		++i;
		--j;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string word;
	cin >> word;
	for(unsigned len = word.length() - 1; len > 0; --len){
		for(unsigned i = 0, j = len; j < word.length(); ++i, ++j){
			if(is_palindrome(word, i, j)){
				cout << len + 1;
				return 0;
			}
		}
	}
	return 0;
}
