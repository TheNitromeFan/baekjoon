#include <iostream>
#include <set>
#include <string>

using namespace std;

bool like(string &code){
	if(code.length() != 7){
		return false;
	}
	set<char> letters_used;
	for(char c : code){
		if(letters_used.find(c) == letters_used.end()){
			letters_used.insert(c);
		}
	}
	if(letters_used.size() != 2){
		return false;
	}
	return code[0] == code[1] && code[0] == code[4] && code[2] == code[3] && code[2] == code[5] && code[2] == code[6];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		string code;
		cin >> code;
		cout << like(code) << '\n';
	}
	return 0;
}
