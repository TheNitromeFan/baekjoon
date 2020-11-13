#include <iostream>
#include <string>

using namespace std;

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		string s, t;
		cin >> s >> t;
		cout << "Distances:";
		for(int j = 0; j < s.length(); ++j){
			cout << ' ' << (t[j] >= s[j] ? t[j] - s[j] : t[j] - s[j] + 26);
		}
		cout << '\n';
	}
	return 0;
}
