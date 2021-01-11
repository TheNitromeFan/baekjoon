#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int w, s, x, y;
	cin >> w >> s >> x >> y;
	vector<vector<int>> work(w);
	for(int i = 0; i < w; ++i){
		work[i].resize(x);
		for(int j = 0; j < x; ++j){
			cin >> work[i][j];
		}
	}
	vector<int> mill(x);
	for(int k = 0; k < s; ++k){
		for(int j = 0; j < x; ++j){
			int z;
			cin >> z;
			mill[j] = max(mill[j], z);
		}
	}
	for(int i = 0; i < w; ++i){
		for(int j = 0; j < x; ++j){
			work[i][j] = min(work[i][j], y - mill[j]);
		}
		for(int j = 0; j < x; ++j){
			cout << work[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
