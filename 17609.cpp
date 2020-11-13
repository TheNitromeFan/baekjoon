#include <iostream>
#include <string>

using namespace std;

bool palindrome(string &s, int i, int j){
	while(i < j){
		if(s[i] != s[j]){
			return false;
		}
		++i;
		--j;
	}
	return true;
}

bool pseudo_palindrome(string &s){
	int i = 0, j = s.length() - 1;
	while(i < j && s[i] == s[j]){
		++i;
		--j;
	}
	return palindrome(s, i + 1, j) || palindrome(s, i, j - 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		string s;
		cin >> s;
		if(palindrome(s, 0, s.length() - 1)){
			cout << 0;
		}else if(pseudo_palindrome(s)){
			cout << 1;
		}else{
			cout << 2;
		}
		cout << '\n';
	}
	return 0;
}
