#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;
	cin >> s;
	int psum[1001] = {};
	for(unsigned i = 0; i < s.length(); ++i){
		psum[i + 1] = psum[i] + (s[i] - '0');
	}
	for(unsigned len = s.length() / 2 * 2; len >= 0; len -= 2){
		for(unsigned i = 0; i + len <= s.length(); ++i){
			if(psum[i + len / 2] - psum[i] == psum[i + len] - psum[i + len / 2]){
				cout << len;
				return 0;
			}
		}
	}
	return 0;
}
