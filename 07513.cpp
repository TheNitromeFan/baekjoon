#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int s;
	cin >> s;
	for(int i = 1; i <= s; ++i){
		cout << "Scenario #" << i << ":\n";
		int m;
		cin >> m;
		vector<string> syl(m, "");
		for(int j = 0; j < m; ++j){
			cin >> syl[j];
		}
		int n;
		cin >> n;
		for(int a0 = 0; a0 < n; ++a0){
			int k;
			cin >> k;
			for(int a1 = 0; a1 < k; ++a1){
				int idx;
				cin >> idx;
				cout << syl[idx];
			}
			cout << '\n';
		}
		cout << '\n';
	}
	return 0;
}
