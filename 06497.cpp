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

void unite(vector<int> &parent, int x, int y){
	int px = find_parent(parent, x);
	int py = find_parent(parent, y);
	if(px != py){
		parent[py] = px;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int m, n;
		cin >> m >> n;
		if(m == 0 && n == 0){
			break;
		}
		vector<tuple<int, int, int>> edges(n);
		long long cost = 0;
		for(int i = 0; i < n; ++i){
			int u, v, w;
			cin >> u >> v >> w;
			edges[i] = make_tuple(u, v, w);
			cost += w;
		}
		sort(edges.begin(), edges.end(), [](tuple<int, int, int> a, tuple<int, int, int> b){
			return get<2>(a) < get<2>(b);
		});
		vector<int> parent(m);
		for(int u = 0; u < m; ++u){
			parent[u] = u;
		}
		int road_cnt = 0;
		for(tuple<int, int, int> edge : edges){
			int u = get<0>(edge), v = get<1>(edge), w = get<2>(edge);
			if(find_parent(parent, u) != find_parent(parent, v)){
				unite(parent, u, v);
				cost -= w;
				++road_cnt;
				if(road_cnt == m - 1){
					break;
				}
			}
		}
		cout << cost << '\n';
	}
	return 0;
}
