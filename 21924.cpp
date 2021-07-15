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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, long long>> edges(m);
	long long total_cost = 0;
	for(int i = 0; i < m; ++i){
		int u, v;
		long long c;
		cin >> u >> v >> c;
		edges[i] = make_tuple(u, v, c);
		total_cost += c;
	}
	vector<int> parent(n + 1);
	for(int u = 1; u <= n; ++u){
		parent[u] = u;
	}
	sort(edges.begin(), edges.end(), [](tuple<int, int, long long> a, tuple<int, int, long long> b){
		return get<2>(a) < get<2>(b);
	});
	int components = n;
	for(tuple<int, int, long long> edge : edges){
		int u = get<0>(edge), v = get<1>(edge);
		long long c = get<2>(edge);
		if(find_parent(parent, u) != find_parent(parent, v)){
			unite(parent, u, v);
			--components;
			total_cost -= c;
			if(components == 1){
				break;
			}
		}
	}
	cout << (components == 1 ? total_cost : -1) << '\n';
	return 0;
}
