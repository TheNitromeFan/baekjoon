#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool palindrome(string s){
	string t = s;
	reverse(t.begin(), t.end());
	return s == t;
}

int main(){
	string s;
	cin >> s;
	cout << (palindrome(s) ? "YES" : "NO");
	return 0;
}
