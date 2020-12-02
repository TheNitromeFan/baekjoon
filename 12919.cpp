#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool transform(string s, string t){
	if(s.length() == t.length()){
		return s == t;
	}
	if(t[t.length() - 1] == 'A'){
		string u = t;
		u.pop_back();
		if(transform(s, u)){
			return true;
		}
	}
	if(t[0] == 'B'){
		string u = t;
		reverse(u.begin(), u.end());
		u.pop_back();
		if(transform(s, u)){
			return true;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s, t;
	cin >> s >> t;
	cout << transform(s, t);
	return 0;
}
