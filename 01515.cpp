#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	unsigned i = 0;
	int n = 0;
	while(i < s.length()){
		++n;
		string t = to_string(n);
		for(unsigned j = 0; j < t.length(); ++j){
			if(i < s.length() && s[i] == t[j]){
				++i;
			}
		}
	}
	cout << n;
	return 0;
}
