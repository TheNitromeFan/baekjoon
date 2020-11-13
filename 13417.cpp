#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int n;
		string s;
		cin >> n;
		for(int j = 0; j < n; ++j){
			string c;
			cin >> c;
			s = min(s + c, c + s);
		}
		cout << s << '\n';
	}
	return 0;
}
