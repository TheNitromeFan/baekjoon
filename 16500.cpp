#include <iostream>
#include <string>
#include <vector>
#define MAX (100 + 1)

using namespace std;

bool match(string &s, string &t, unsigned pos){
	if(pos + t.length() > s.length()){
		return false;
	}
	for(unsigned i = 0; i < t.length(); ++i){
		if(t[i] != s[pos + i]){
			return false;
		}
	}
	return true;
}

bool search(vector<string> &a, string &s, bool dp[MAX], unsigned pos){
	if(dp[pos]){
		return true;
	}
	if(pos == s.length()){
		dp[pos] = true;
		return true;
	}
	for(string word : a){
		if(match(s, word, pos)){
			dp[pos] |= search(a, s, dp, pos + word.length());
		}
	}
	return dp[pos];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int n;
	cin >> n;
	vector<string> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	bool dp[MAX] = {};
	cout << search(a, s, dp, 0);
	return 0;
}
