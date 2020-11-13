#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string line;
	getline(cin, line);
	for(int i = 0; i < n; ++i){
		getline(cin, line);
		int cnt[26] = {};
		char max_char = ' ';
		int max_cnt = 0;
		for(char c : line){
			if(c >= 'a' && c <= 'z'){
				++cnt[c - 'a'];
				if(cnt[c - 'a'] > max_cnt){
					max_char = c;
					max_cnt = cnt[c - 'a'];
				}else if(cnt[c - 'a'] == max_cnt){
					max_char = '?';
				}
			}
		}
		cout << max_char << '\n';
	}
	return 0;
}
