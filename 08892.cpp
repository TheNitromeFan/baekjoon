#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool palindrome(string &s){
	string t = s;
	reverse(t.begin(), t.end());
	return s == t;
}

string password(vector<string> &v){
	for(unsigned i = 0; i < v.size(); ++i){
		for(unsigned j = 0; j < v.size(); ++j){
			if(i == j){
				continue;
			}
			string ans = v[i] + v[j];
			if(palindrome(ans)){
				return ans;
			}
		}
	}
	return "0";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int k;
		cin >> k;
		vector<string> words(k, "");
		for(int j = 0; j < k; ++j){
			cin >> words[j];
		}
		cout << password(words) << '\n';
	}
	return 0;
}
