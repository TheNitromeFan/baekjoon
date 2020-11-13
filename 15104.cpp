#include <iostream>
#include <string>

using namespace std;

bool palindrome(string s, unsigned start, unsigned end){
	for(unsigned i = start, j = end - 1; i < j; ++i, --j){
		if(s[i] != s[j]){
			return false;
		}
	}
	return true;
}

bool odd(string s){
	for(unsigned len = 2; len <= s.length(); ++len){
		for(unsigned i = 0; i + len <= s.length(); ++i){
			if(palindrome(s, i, i + len) && len % 2 == 0){
				return false;
			}
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	cout << (odd(s) ? "Odd." : "Or not.");
	return 0;
}
