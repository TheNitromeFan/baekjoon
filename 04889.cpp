#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	int t = 0;
	while(true){
		cin >> s;
		if(s[0] == '-'){
			break;
		}
		++t;
		int cnt = 0;
		int ans = 0;
		for(char p : s){
			if(p == '{'){
				++cnt;
			}else if(p == '}' && cnt == 0){
				++ans;
				++cnt;
			}else{
				--cnt;
			}
		}
		ans += cnt / 2;
		cout << t << ". " << ans << "\n";
	}
	return 0;
}
