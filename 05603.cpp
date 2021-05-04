#include <iostream>
#include <string>

using namespace std;

string encode(string &s){
	string ret;
	unsigned pos = 0;
	while(pos < s.length()){
		unsigned start = pos;
		unsigned cnt = 0;
		while(pos < s.length() && s[pos] == s[start]){
			++pos;
			++cnt;
		}
		ret += to_string(cnt) + s[start];
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string s;
	cin >> s;
	for(int i = 0; i < n; ++i){
		s = encode(s);
	}
	cout << s;
	return 0;
}
