#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int ans = 0;
	for(unsigned idx = 0; idx < s.length(); ++idx){
		int cnt = 0;
		while(idx + 1 < s.length() && s[idx + 1] == s[idx] + 1){
			++idx;
			++cnt;
		}
		if(cnt == 2){
			++ans;
		}
	}
	cout << ans;
	return 0;
}
