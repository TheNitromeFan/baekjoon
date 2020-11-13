#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;
	cin >> s;
	for(char c : s){
		char tmp;
		if(c <= 'Z'){
			tmp = c - 'A' + 'a';
		}else{
			tmp = c - 'a' + 'A';
		}
		cout << tmp;
	}
	return 0;
}
