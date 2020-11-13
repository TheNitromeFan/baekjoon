#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		string str;
		cin >> str;
		unsigned n = str.length() / 2;
		cout << (str[n - 1] == str[n] ? "Do-it" : "Do-it-Not") << '\n';
	}
	return 0;
}
