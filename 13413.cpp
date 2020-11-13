#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int moves(string s, string t){
	int a = 0, b = 0;
	for(unsigned i = 0; i < s.length(); ++i){
		if(s[i] == 'B' && t[i] == 'W'){
			++a;
		}else if(s[i] == 'W' && t[i] == 'B'){
			++b;
		}
	}
	return max(a, b);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int n;
		string s, g;
		cin >> n >> s >> g;
		cout << moves(s, g) << '\n';
	}
	return 0;
}
