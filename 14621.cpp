#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

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

int mst(vector<tuple<int, int, int>> &edges, vector<bool> &m, int n){
	sort(edges.begin(), edges.end(), [](tuple<int, int, int> a, tuple<int, int, int> b){
		return get<2>(a) < get<2>(b);
	});
	vector<int> parent(n + 1);
	for(int u = 1; u <= n; ++u){
		parent[u] = u;
	}
	int ret = 0;
	int edge_count = 0;
	for(tuple<int, int, int> edge : edges){
		int u = get<0>(edge), v = get<1>(edge), w = get<2>(edge);
		if((m[u] ^ m[v]) && find_parent(parent, u) != find_parent(parent, v)){
			ret += w;
			++edge_count;
			unite(parent, u, v);
			if(edge_count == n - 1){
				break;
			}
		}
	}
	if(edge_count == n - 1){
		return ret;
	}else{
		return -1;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<bool> male(n + 1);
	for(int u = 1; u <= n; ++u){
		char c;
		cin >> c;
		male[u] = (c == 'M');
	}
	vector<tuple<int, int, int>> edges(m);
	for(int i = 0; i < m; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		edges[i] = make_tuple(u, v, w);
	}
	cout << mst(edges, male, n);
	return 0;
}
