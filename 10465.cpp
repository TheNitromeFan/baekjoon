#include <iostream>
#include <string>
#include <map>

using namespace std;

char most_occuring(map<char, int> &cnt){
	char ret = 'a';
	for(char c = 'b'; c <= 'z'; ++c){
		if(cnt[c] > cnt[ret]){
			ret = c;
		}
	}
	return ret;
}

char shift(char a, char b){
	int ret = a + (b - 'a' + 1);
	if(ret > 'z'){
		ret -= 26;
	}
	return (char)ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unsigned k;
	cin >> k;
	string s;
	cin >> s;
	map<char, int> cnt;
	string output;
	for(unsigned i = 0; i < k && i < s.length(); ++i){
		++cnt[s[i]];
		output += s[i];
	}
	for(unsigned i = k; i < s.length(); ++i){
		char c = most_occuring(cnt);
		output += shift(s[i], c);
		++cnt[s[i]];
		--cnt[s[i - k]];
	}
	cout << output;
	return 0;
}
