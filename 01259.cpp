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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		string num;
		cin >> num;
		if(num == "0"){
			break;
		}
		cout << (palindrome(num) ? "yes" : "no") << '\n';
	}
	return 0;
}
