#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

bool all_asterisks(string &s){
	for(char c : s){
		if(c != '*'){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int pic[202][202];
	while(true){
		unsigned n = 0;
		string s;
		memset(pic, 0, sizeof(pic));
		while(true){
			getline(cin, s);
			if(all_asterisks(s)){
				break;
			}
			for(unsigned j = 0; j < s.length(); ++j){
				pic[n][j] = s[j];
			}
			++n;
		}
		if(n == 0){
			break;
		}
		for(unsigned i = 0; i < n; ++i){
			for(unsigned j = 0; pic[i][j] != 0; ++j){
				cout << (char)pic[i][j];
			}
			cout << '\n';
		}
	}
	return 0;
}
