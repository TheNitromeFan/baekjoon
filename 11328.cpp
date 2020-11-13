#include <iostream>
#include <string>
#include <map>

using namespace std;

bool equal_maps(map<char, int> &a, map<char, int> &b){
	for(char c = 'a'; c <= 'z'; ++c){
		if(a[c] != b[c]){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		map<char, int> cnt1, cnt2;
		for(char a = 'a'; a <= 'z'; ++a){
			cnt1[a] = 0;
			cnt2[a] = 0;
		}
		string s1, s2;
		cin >> s1 >> s2;
		for(char c : s1){
			++cnt1[c];
		}
		for(char c : s2){
			++cnt2[c];
		}
		cout << (equal_maps(cnt1, cnt2) ? "Possible" : "Impossible") << '\n';
	}
	return 0;
}
