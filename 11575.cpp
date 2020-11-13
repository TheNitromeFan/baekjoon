#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int a, b;
		string s;
		cin >> a >> b >> s;
		a %= 26;
		b %= 26;
		for(char c : s){
			char d = (a * (c - 'A') + b) % 26 + 'A';
			cout << d;
		}
		cout << '\n';
	}
	return 0;
}
