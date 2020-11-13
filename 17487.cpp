#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	getline(cin, s);
	int left = 0, right = 0, space = 0;
	for(char c : s){
		if(c == ' '){
			++space;
			continue;
		}
		if(c >= 'A' && c <= 'Z'){
			++space;
			c += 'a' - 'A';
		}
		switch(c){
			case 'u':
			case 'i':
			case 'o':
			case 'p':
			case 'h':
			case 'j':
			case 'k':
			case 'l':
			case 'n':
			case 'm':
				++right;
				break;
			default:
				++left;
				break;
		}
	}
	if(left < right){
		if(left + space < right){
			left += space;
			space = 0;
		}else{
			space -= right - left;
			left = right;
		}
	}else if(left > right){
		if(left > right + space){
			right += space;
			space = 0;
		}else{
			space -= left - right;
			right = left;
		}
	}
	left += space / 2;
	right += space / 2;
	left += space % 2;
	cout << left << ' ' << right;
	return 0;
}
