#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string line;
	bool capital = false;
	while(getline(cin, line)){
		for(char c : line){
			cout << (char)(capital ? toupper(c) : tolower(c));
			if(c == '.' || c == '?' || c == '!'){
				capital = true;
			}else if(!(isspace(c) || c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']')){
				capital = false;
			}
		}
		cout << '\n';
	}
	return 0;
}
