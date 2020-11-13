#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		string line;
		cin >> line;
		bool appears[26] = {};
		for(char c : line){
			appears[c - 'A'] = true;
		}
		int ans = 0;
		for(int i = 0; i < 26; ++i){
			if(!appears[i]){
				ans += i + 65;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
