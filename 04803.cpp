#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int find_parent(vector<int> &parent, int x){
	if(parent[x] == x){
		return x;
	}else{
		parent[x] = find_parent(parent, parent[x]);
		return parent[x];
	}
}

void unite(vector<int> &parent, vector<int> &component_sizes, int x, int y){
	int px = find_parent(parent, x), py = find_parent(parent, y);
	if(px != py){
		parent[py] = px;
		component_sizes[px] += component_sizes[py];
		component_sizes[py] = 0;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 0;
	while(true){
		int n, m;
		cin >> n >> m;
		if(n == 0 && m == 0){
			break;
		}
		++t;
		vector<int> parent(n + 1);
		vector<int> component_sizes(n + 1, 1);
		for(int u = 1; u <= n; ++u){
			parent[u] = u;
		}
		vector<int> edges;
		for(int i = 0; i < m; ++i){
			int a, b;
			cin >> a >> b;
			unite(parent, component_sizes, a, b);
			edges.push_back(a);
		}
		vector<int> component_edges(n + 1);
		for(int v : edges){
			int p = find_parent(parent, v);
			++component_edges[p];
		}
		/*
		for(int u = 1; u <= n; ++u){
			cout << component_sizes[u] << ' ' << component_edges[u] << '\n';
		}
		*/
		int trees = 0;
		for(int u = 1; u <= n; ++u){
			if(component_sizes[u] == component_edges[u] + 1){
				++trees;
			}
		}
		if(trees > 1){
			cout << "Case " << t << ": A forest of " << trees << " trees.\n";
		}else if(trees == 1){
			cout << "Case " << t << ": There is one tree.\n";
		}else{
			cout << "Case " << t << ": No trees.\n";
		}
	}
	return 0;
}
