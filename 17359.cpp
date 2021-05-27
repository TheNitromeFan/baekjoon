#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a = 0, b = 0, c = 0, d = 0;
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		string s;
		cin >> s;
		for(unsigned j = 0; j + 1 < s.length(); ++j){
			if(s[j] != s[j + 1]){
				++cnt;
			}
		}
		if(s[0] == '0' && s.back() == '1'){
			++a;
		}else if(s[0] == '1' && s.back() == '0'){
			++b;
		}else if(s[0] == '0' && s.back() == '0'){
			++c;
		}else if(s[0] == '1' && s.back() == '1'){
			++d;
		}
	}
	if(a > 0 || b > 0){
		cnt += max(0, abs(b - a) - 1);
	}else{
		cnt += (c > 0 && d > 0);
	}
	cout << cnt;
	return 0;
}
