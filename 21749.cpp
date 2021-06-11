#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	unordered_map<char, int> cnt;
	string key;
	int max_cnt = 0;
	while(getline(cin, s)){
		for(char c : s){
			if(isspace(c)){
				continue;
			}
			if(cnt.find(c) == cnt.end()){
				key += c;
				cnt[c] = 0;
			}
			++cnt[c];
			if(max_cnt < cnt[c]){
				max_cnt = cnt[c];
			}
		}
	}
	sort(key.begin(), key.end());
	for(int h = max_cnt; h >= 1; --h){
		for(char c : key){
			if(cnt[c] >= h){
				cout << '#';
			}else{
				cout << ' ';
			}
		}
		cout << '\n';
	}
	cout << key << '\n';
	return 0;
}
