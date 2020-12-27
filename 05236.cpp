#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		string s;
		cin >> s;
		reverse(s.begin(), s.end());
		string ans = "";
		for(unsigned idx = 0; idx < s.length(); ++idx){
			if(idx == 0 || s[idx] > s[idx - 1]){
				ans += s[idx];
			}else{
				break;
			}
		}
		reverse(s.begin(), s.end());
		reverse(ans.begin(), ans.end());
		cout << "The longest decreasing suffix of " << s << " is " << ans << "\n";
	}
	return 0;
}
