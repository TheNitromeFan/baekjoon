#include <iostream>
#include <string>

using namespace std;

bool match(string s, string t, unsigned x){
	if(x + t.length() > s.length()){
		return false;
	}
	for(unsigned i = 0; i < t.length(); ++i){
		if(s[x + i] != t[i]){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string to_find;
	cin >> to_find;
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 0; i < n; ++i){
		string ring;
		cin >> ring;
		string extended = ring + ring;
		for(unsigned j = 0; j < 10; ++j){
			if(match(extended, to_find, j)){
				++ans;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
