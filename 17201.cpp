#include <iostream>
#include <string>

using namespace std;

bool good(string s){
	for(unsigned i = 0; i < s.length() - 1; ++i){
		if(s[i] == s[i + 1]){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unsigned n;
	cin >> n;
	string s;
	cin >> s;
	cout << (good(s) ? "Yes" : "No");
	return 0;
}
