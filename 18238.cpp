#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int ans = 0;
	char cur = 'A';
	for(char c : s){
		int cw, ccw;
		if(c >= cur){
			cw = c - cur;
			ccw = cur + 26 - c;
		}else{
			cw = c + 26 - cur;
			ccw = cur - c;
		}
		ans += min(cw, ccw);
		cur = c;
	}
	cout << ans;
	return 0;
}
