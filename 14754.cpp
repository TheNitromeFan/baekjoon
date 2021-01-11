#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define MAX 1000

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int grid[MAX][MAX];
	vector<pair<int, int>> coords;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> grid[i][j];
			coords.push_back(make_pair(i, j));
		}
	}
	sort(coords.begin(), coords.end(), [&grid](pair<int, int> a, pair<int, int> b){
		int ax = a.first, ay = a.second, bx = b.first, by = b.second;
		return grid[ax][ay] > grid[bx][by];
	});
	bool rows[MAX] = {}, cols[MAX] = {};
	long long heights = 0;
	for(pair<int, int> p : coords){
		int x = p.first, y = p.second;
		if(rows[x] && cols[y]){
			heights += grid[x][y];
		}
		rows[x] = true;
		cols[y] = true;
	}
	cout << heights;
	return 0;
}
