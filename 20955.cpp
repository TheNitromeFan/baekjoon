#include <iostream>
#include <vector>

using namespace std;

int find_parent(vector<int> &parent, int x){
	if(parent[x] == x){
		return x;
	}else{
		parent[x] = find_parent(parent, parent[x]);
		return parent[x];
	}
}

void unite(vector<int> &parent, int x, int y){
	int px = find_parent(parent, x);
	int py = find_parent(parent, y);
	parent[py] = px;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> parent(n + 1);
	for(int u = 1; u <= n; ++u){
		parent[u] = u;
	}
	int components = n;
	int operations = 0;
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		if(find_parent(parent, u) != find_parent(parent, v)){
			unite(parent, u, v);
			--components;
		}else{
			++operations;
		}
	}
	operations += components - 1;
	cout << operations << '\n';
	return 0;
}
