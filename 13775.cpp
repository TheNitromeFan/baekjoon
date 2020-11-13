#include <iostream>
#include <string>

using namespace std;

int main(){
	int key;
	cin >> key;
	string line;
	getline(cin, line);
	getline(cin, line);
	for(char c : line){
		if(c >= 'a' && c <= 'z'){
			c -= key;
			if(c < 'a'){
				c += 26;
			}
			++key;
			if(key == 26){
				key = 1;
			}
		}
		cout << c;
	}
	return 0;
}
