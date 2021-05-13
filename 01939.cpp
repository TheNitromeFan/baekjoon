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
	int start, end;
	cin >> start >> end;
	sort(edges.begin(), edges.end(), [](tuple<int, int, int> a, tuple<int, int, int> b){
		return get<2>(a) > get<2>(b);
	});
	vector<int> parent(n + 1);
	for(int u = 1; u <= n; ++u){
		parent[u] = u;
	}
	int ans = get<2>(edges[0]);
	int idx = 0;
	while(find_parent(parent, start) != find_parent(parent, end)){
		tuple<int, int, int> edge = edges[idx];
		int u = get<0>(edge), v = get<1>(edge);
		ans = get<2>(edge);
		unite(parent, u, v);
		++idx;
	}
	cout << ans;
	return 0;
}
