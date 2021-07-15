#include <iostream>
#include <string>
#define MOD 1000000007

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 1; a0 <= t; ++a0){
		string s;
		cin >> s;
		long long ans = 1;
		cout << "Case #" << a0 << ": ";
		if(s.length() == 1){
			cout << ans << "\n";
			continue;
		}
		for(unsigned i = 0; i < s.length(); ++i){
			if(i > 0 && i + 1 < s.length()){
				if(s[i - 1] != s[i] && s[i] != s[i + 1] && s[i - 1] != s[i + 1]){
					ans *= 3;
				}else if(s[i - 1] != s[i] || s[i] != s[i + 1] || s[i - 1] != s[i + 1]){
					ans *= 2;
				}
			}else if((i == 0 && s[0] != s[1]) || (i + 1 == s.length() && s[i - 1] != s[i])){
				ans *= 2;
			}
			ans %= MOD;
		}
		cout << ans << "\n";
	}
	return 0;
}
