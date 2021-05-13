#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool evenly_spaced(string &s){
	vector<vector<unsigned>> pos(26);
	for(unsigned i = 0; i < s.length(); ++i){
		char c = s[i];
		int idx = c - 'a';
		for(unsigned j : pos[idx]){
			if(i % 2 == j % 2){
				return false;
			}
		}
		pos[idx].push_back(i);
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	cout << (evenly_spaced(s) ? "YES" : "NO");
	return 0;
}
