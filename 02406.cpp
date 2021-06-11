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

int find_cost(vector<tuple<int, int, int>> &edges, vector<int> &parent, int n, int comps, vector<tuple<int, int>> &ans){
	sort(edges.begin(), edges.end(), [](tuple<int, int, int> a, tuple<int, int, int> b){
		return get<2>(a) < get<2>(b);
	});
	int ret = 0;
	for(unsigned idx = 0; idx < edges.size() && comps > 1; ++idx){
		tuple<int, int, int> t = edges[idx];
		int u = get<0>(t), v = get<1>(t), w = get<2>(t);
		if(find_parent(parent, u) != find_parent(parent, v)){
			unite(parent, u, v);
			--comps;
			ret += w;
			ans.push_back(make_tuple(u, v));
		}
	}
	return ret;
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
	int comps = n - 1;
	for(int a0 = 0; a0 < m; ++a0){
		int u, v;
		cin >> u >> v;
		if(find_parent(parent, u) != find_parent(parent, v)){
			unite(parent, u, v);
			--comps;
		}
	}
	vector<tuple<int, int, int>> edges;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			int cost;
			cin >> cost;
			if(j > 1 && j < i){
				edges.push_back(make_tuple(j, i, cost));
			}
		}
	}
	vector<tuple<int, int>> ans;
	int x = find_cost(edges, parent, n, comps, ans);
	cout << x << ' ' << ans.size() << '\n';
	for(tuple<int, int> y : ans){
		cout << get<0>(y) << ' ' << get<1>(y) << '\n';
	}
	return 0;
}
