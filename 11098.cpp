#include <iostream>
#include <string>
#include <utility>

using namespace std;

int main(){
	int n;
	cin >> n;
	for(int a0 = 0; a0 < n; ++a0){
		int p;
		cin >> p;
		pair<int, string> ans = make_pair(0, "");
		for(int a1 = 0; a1 < p; ++a1){
			int c;
			string name;
			cin >> c >> name;
			if(c > ans.first){
				ans = make_pair(c, name);
			}
		}
		cout << ans.second << '\n';
	}
	return 0;
}
