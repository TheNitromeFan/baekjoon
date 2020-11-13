#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	string s;
	while(cin >> s){
		string t = s;
		sort(t.begin(), t.end());
		int cnt = 0;
		for(unsigned i = 0; i < s.length(); ++i){
			unsigned j = s.find(t[i]);
			if(i != j){
				++cnt;
				swap(s[i], s[j]);
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
