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
	vector<tuple<int, int, int>> edges(m);
	for(int i = 0; i < m; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		edges[i] = make_tuple(u, v, w);
	}
	sort(edges.begin(), edges.end(), [](tuple<int, int, int> a, tuple<int, int, int> b){
		return get<2>(a) < get<2>(b);
	});
	vector<int> parent(n + 1);
	for(int u = 1; u <= n; ++u){
		parent[u] = u;
	}
	int cost = 0;
	int edge_cnt = 0;
	for(tuple<int, int, int> t : edges){
		int u = get<0>(t), v = get<1>(t), w = get<2>(t);
		if(find_parent(parent, u) != find_parent(parent, v)){
			// cout << u << ' ' << v << ' ' << w << '\n';
			cost += w;
			++edge_cnt;
			unite(parent, u, v);
			if(edge_cnt == n - 2){
				break;
			}
		}
	}
	cout << cost;
	return 0;
}
