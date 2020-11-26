#include <iostream>
#include <string>

using namespace std;

int code(char c){
	switch(c){
		case 'B':
		case 'F':
		case 'P':
		case 'V':
			return 1;
		case 'C':
		case 'G':
		case 'J':
		case 'K':
		case 'Q':
		case 'S':
		case 'X':
		case 'Z':
			return 2;
		case 'D':
		case 'T':
			return 3;
		case 'L':
			return 4;
		case 'M':
		case 'N':
			return 5;
		case 'R':
			return 6;
		default:
			return 0;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string word;
	while(cin >> word){
		unsigned idx = 0;
		while(idx < word.length()){
			int num = code(word[idx]);
			if(num == 0){
				++idx;
				continue;
			}
			while(idx < word.length() && num == code(word[idx])){
				++idx;
			}
			cout << num;
		}
		cout << '\n';
	}
	return 0;
}
