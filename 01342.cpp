#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool lucky(string &s){
	for(unsigned i = 0; i + 1 < s.length(); ++i){
		if(s[i] == s[i + 1]){
			return false;
		}
	}
	return true;
}

int main(){
	string s;
	cin >> s;
	int ans = 0;
	sort(s.begin(), s.end());
	do{
		if(lucky(s)){
			++ans;
		}
	}while(next_permutation(s.begin(), s.end()));
	cout << ans;
	return 0;
}
