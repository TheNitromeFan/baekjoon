#include <iostream>
#include <string>

using namespace std;

bool vowel(char c){
	bool ret = false;
	switch(c){
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			ret = true;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		string word;
		cin >> word;
		if(word == "#"){
			break;
		}
		unsigned idx = 0;
		while(idx < word.length() && !vowel(word[idx])){
			++idx;
		}
		cout << word.substr(idx, word.length() - idx) + word.substr(0, idx) + "ay\n";
	}
	return 0;
}
