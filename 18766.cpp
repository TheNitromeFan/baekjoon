#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		cin >> n;
		vector<string> before(n), after(n);
		for(int i = 0; i < n; ++i){
			cin >> before[i];
		}
		for(int i = 0; i < n; ++i){
			cin >> after[i];
		}
		sort(before.begin(), before.end());
		sort(after.begin(), after.end());
		cout << (before == after ? "NOT CHEATER" : "CHEATER") << '\n';
	}
	return 0;
}
