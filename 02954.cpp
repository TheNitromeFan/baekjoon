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
			break;
	}
	return ret;
}

int main(){
	string sentence;
	getline(cin, sentence);
	unsigned idx = 0;
	while(idx < sentence.length()){
		cout << sentence[idx];
		if(vowel(sentence[idx])){
			idx += 2;
		}
		++idx;
	}
	return 0;
}
