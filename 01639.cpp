#include <iostream>
#include <string>

using namespace std;

unsigned ans(string &s){
	for(unsigned len = (s.length() / 2) * 2; len > 0; len -= 2){
		for(unsigned idx = 0; idx + len <= s.length(); ++idx){
			unsigned i = idx, j = idx + len - 1;
			int sum = 0;
			while(i < j){
				sum += s[i] - s[j];
				++i;
				--j;
			}
			if(sum == 0){
				return len;
			}
		}
	}
	return 0;
}

int main(){
	string s;
	cin >> s;
	cout << ans(s);
	return 0;
}
