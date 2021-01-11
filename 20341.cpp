#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int>> v(n);
	for(int j = 0; j < 3; ++j){
		for(int i = 0; i < n; ++i){
			int k;
			cin >> k;
			v[i].push_back(k);
		}
	}
	for(int i = 0; i < n; ++i){
		sort(v[i].begin(), v[i].end());
		cout << v[i][1] << ' ';
	}
	return 0;
}
