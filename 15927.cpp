#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(string &s){
	for(unsigned i = 0; 2 * i < s.length(); ++i){
		if(s[i] != s[s.length() - 1 - i]){
			return false;
		}
	}
	return true;
}

bool all_same(string &s){
	for(char c : s){
		if(c != s[0]){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	getline(cin, s);
	if(!is_palindrome(s)){
		cout << s.length();
	}else if(all_same(s)){
		cout << -1;
	}else{
		cout << s.length() - 1;
	}
	return 0;
}
