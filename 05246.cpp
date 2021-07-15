#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int n;
		cin >> n;
		vector<int> v(9);
		int ans = 0;
		for(int j = 0; j < n; ++j){
			int row, col;
			cin >> row >> col;
			++v[col];
			ans = max(ans, v[col]);
		}
		cout << ans << '\n';
	}
	return 0;
}
