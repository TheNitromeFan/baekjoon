#include <iostream>
#include <string>
#define MAX 1000

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	unsigned n = s.length();
	s = " " + s;
	bool is_palindrome[MAX + 1][MAX + 1];
	for(unsigned i = 1; i <= n; ++i){
		is_palindrome[i][i] = true;
	}
	for(unsigned i = 1; i + 1 <= n; ++i){
		is_palindrome[i][i + 1] = (s[i] == s[i + 1]);
	}
	for(unsigned len = 3; len <= n; ++len){
		for(unsigned i = 1; i + len - 1 <= n; ++i){
			unsigned j = i + len - 1;
			is_palindrome[i][j] = (is_palindrome[i + 1][j - 1] && (s[i] == s[j]));
		}
	}
	unsigned to_add[MAX + 1] = {};
	for(unsigned i = n - 1; i > 0; --i){
		if(is_palindrome[i][n]){
			to_add[i] = 0;
		}else{
			to_add[i] = to_add[i + 1] + 1;
		}
	}
	cout << n + to_add[1];
	return 0;
}
