#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s, t;
	cin >> s >> t;
	while(s.length() < t.length()){
		if(t[t.length() - 1] == 'B'){
			t.pop_back();
			reverse(t.begin(), t.end());
		}else{
			t.pop_back();
		}
	}
	cout << (s == t);
	return 0;
}
