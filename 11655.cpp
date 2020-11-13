#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;
	getline(cin, s);
	for(char &c : s){
		if((c >= 'A' && c <= 'M') || (c >= 'a' && c <= 'm')){
			c += 13;
		}else if((c >= 'N' && c <= 'Z') || (c >= 'n' && c <= 'z')){
			c -= 13;
		}
	}
	cout << s;
	return 0;
}
