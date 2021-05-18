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
	if(px != py){
		parent[py] = px;
	}
}

int min_load(vector<tuple<int, int, int>> &edges, int n, int start, int end){
	sort(edges.begin(), edges.end(), [](tuple<int, int, int> a, tuple<int, int, int> b){
		return get<2>(a) > get<2>(b);
	});
	vector<int> parent(n + 1);
	for(int v = 1; v <= n; ++v){
		parent[v] = v;
	}
	for(tuple<int, int, int> edge : edges){
		int u = get<0>(edge), v = get<1>(edge);
		unite(parent, u, v);
		if(find_parent(parent, start) == find_parent(parent, end)){
			return get<2>(edge);
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int s, e;
	cin >> s >> e;
	vector<tuple<int, int, int>> edges(m);
	for(int i = 0; i < m; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		edges[i] = make_tuple(u, v, w);
	}
	cout << min_load(edges, n, s, e);
	return 0;
}
