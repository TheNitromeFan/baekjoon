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

void unite(vector<int> &parent, int x, int y){
	int px = find_parent(parent, x);
	int py = find_parent(parent, y);
	parent[py] = px;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> parent(n + 1);
	for(int u = 1; u <= n; ++u){
		parent[u] = u;
	}
	for(int i = 0; i < n - 2; ++i){
		int u, v;
		cin >> u >> v;
		unite(parent, u, v);
	}
	int p1 = find_parent(parent, 1);
	for(int u = 2; u <= n; ++u){
		int pu = find_parent(parent, u);
		if(pu != p1){
			cout << 1 << ' ' << u << '\n';
			break;
		}
	}
	return 0;
}
