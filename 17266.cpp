#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	unsigned m;
	cin >> m;
	vector<int> pos(m);
	for(unsigned i = 0; i < m; ++i){
		cin >> pos[i];
	}
	int height = max(pos[0], n - pos[m - 1]);
	for(unsigned i = 0; i + 1 < m; ++i){
		height = max(height, (pos[i + 1] - pos[i] + 1) / 2);
	}
	cout << height;
	return 0;
}
