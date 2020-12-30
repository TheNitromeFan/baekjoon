#include <iostream>
#include <vector>

using namespace std;

int find_parent(vector<int> &parent, int x){
	if(parent[x] == x){
		return x;
	}
	parent[x] = find_parent(parent, parent[x]);
	return parent[x];
}

void merge(vector<int> &parent, int x, int y){
	int px = find_parent(parent, x), py = find_parent(parent, y);
	if(px != py){
		parent[py] = px;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> parent(n + 1);
	for(int i = 1; i <= n; ++i){
		parent[i] = i;
	}
	int cnt = n;
	for(int j = 0; j < m; ++j){
		int x, y;
		cin >> x >> y;
		while(find_parent(parent, y) != find_parent(parent, x)){
			--cnt;
			int tmp = find_parent(parent, y) - 1;
			merge(parent, x, y);
			y = tmp;
		}
	}
	cout << cnt;
	return 0;
}
