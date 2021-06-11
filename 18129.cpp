#include <iostream>
#include <cctype>
#include <vector>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	string::size_type k;
	cin >> s >> k;
	string::size_type idx = 0;
	string ans;
	vector<bool> replaced(100);
	while(idx < s.length()){
		string::size_type start = idx;
		char c = toupper(s[start]);
		if(replaced[c]){
			++idx;
			continue;
		}
		while(idx < s.length() && toupper(s[idx]) == c){
			++idx;
		}
		if(idx - start >= k){
			ans += '1';
		}else{
			ans += '0';
		}
		replaced[c] = true;
	}
	cout << ans;
	return 0;
}
