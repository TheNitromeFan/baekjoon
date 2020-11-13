#include <iostream>
#include <string>

using namespace std;

bool hiss(string word){
	for(unsigned i = 0; i + 1 < word.length(); ++i){
		if(word[i] == 's' && word[i + 1] == 's'){
			return true;
		}
	}
	return false;
}

int main(){
	string word;
	cin >> word;
	cout << (hiss(word) ? "hiss" : "no hiss");
	return 0;
}
