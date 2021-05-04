#include <iostream>
#include <string>

using namespace std;

string decode(string &s){
	string ret;
	for(unsigned i = 0, j = 1; i < s.length(); i += 2, j += 2){
		for(char c = '0'; c < s[i]; ++c){
			ret += s[j];
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	unsigned pos;
	cin >> k >> pos;
	string s;
	cin >> s;
	for(int i = 0; i < k; ++i){
		s = decode(s);
	}
	cout << s[pos];
	return 0;
}
