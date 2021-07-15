#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n, k;
		string s;
		cin >> n >> k >> s;
		int cnt = 0;
		int i = 0, j = 0;
		while(j < n){
			if(s[j] == 'K'){
				++cnt;
			}
			++j;
			if(cnt == k){
				break;
			}
		}
		int ans = j;
		while(j < n){
			while(j < n && s[j] == 'T'){
				++j;
			}
			ans = max(ans, j - i);
			++j;
			while(i < n && s[i] == 'T'){
				++i;
			}
			++i;
		}
		cout << ans << '\n';
	}
	return 0;
}
