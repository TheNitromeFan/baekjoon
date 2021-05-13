#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int find_parent(vector<int> &parent, int x){
	if(parent[x] == x){
		return x;
	}else{
		parent[x] = find_parent(parent, parent[x]);
		return parent[x];
	}
}

void unite(vector<int> &parent, vector<int> &component, int x, int y){
	x = find_parent(parent, x);
	y = find_parent(parent, y);
	if(x != y){
		parent[y] = x;
		component[x] += component[y];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	vector<tuple<int, int, int>> edges(n - 1);
	for(int i = 0; i < n - 1; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		edges[i] = make_tuple(u, v, w);
	}
	vector<tuple<int, int, int>> queries(q);
	for(int i = 0; i < q; ++i){
		int k, v;
		cin >> k >> v;
		queries[i] = make_tuple(i, k, v);
	}
	sort(edges.begin(), edges.end(), [](tuple<int, int, int> a, tuple<int, int, int> b){
		return get<2>(a) > get<2>(b);
	});
	/*
	for(tuple<int, int, int> t : edges){
		cout << get<0>(t) << ' ' << get<1>(t) << ' ' << get<2>(t) << '\n';
	}
	*/
	sort(queries.begin(), queries.end(), [](tuple<int, int, int> a, tuple<int, int, int> b){
		return get<1>(a) > get<1>(b);
	});
	/*
	for(tuple<int, int, int> t : queries){
		cout << get<0>(t) << ' ' << get<1>(t) << ' ' << get<2>(t) << '\n';
	}
	*/
	vector<int> parent(n + 1), component_size(n + 1);
	for(int u = 1; u <= n; ++u){
		parent[u] = u;
		component_size[u] = 1;
	}
	int idx = 0;
	vector<tuple<int, int>> ans(q);
	for(int a0 = 0; a0 < q; ++a0){
		while(idx < n - 1 && get<2>(edges[idx]) >= get<1>(queries[a0])){
			unite(parent, component_size, get<0>(edges[idx]), get<1>(edges[idx]));
			++idx;
		}
		// cout << idx << ' ' << component_size[get<2>(queries[a0])] << '\n';
		ans[a0] = make_tuple(get<0>(queries[a0]), component_size[find_parent(parent, get<2>(queries[a0]))] - 1);
	}
	sort(ans.begin(), ans.end());
	for(tuple<int, int> t : ans){
		cout << get<1>(t) << '\n';
	}
	return 0;
}
