#include <iostream>
#include <string>

using namespace std;

int main(){
	int t;
	cin >> t;
	string line;
	getline(cin, line);
	for(int i = 1; i <= t; ++i){
		string s;
		getline(cin, s);
		cout << "Case #" << i << ": ";
		string ans[1000];
		int ind = 0;
		for(char c : s){
			if(c == ' '){
				++ind;
			}else{
				ans[ind] += c;
			}
		}
		for(int j = ind; j >= 0; --j){
			cout << ans[j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
