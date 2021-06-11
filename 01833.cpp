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
	int n;
	cin >> n;
	vector<int> parent(n + 1);
	for(int v = 1; v <= n; ++v){
		parent[v] = v;
	}
	int comps = n;
	vector<tuple<int, int, int>> edges;
	int cost = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			int aij;
			cin >> aij;
			if(j >= i){
				continue;
			}
			if(aij < 0){
				cost += -aij;
				if(find_parent(parent, i) != find_parent(parent, j)){
					unite(parent, i, j);
					--comps;
				}
			}else if(aij > 0){
				edges.push_back(make_tuple(i, j, aij));
			}
		}
	}
	sort(edges.begin(), edges.end(), [](tuple<int, int, int> t1, tuple<int, int, int> t2){
		return get<2>(t1) < get<2>(t2);
	});
	int edge_cnt = 0;
	vector<tuple<int, int>> added;
	for(unsigned idx = 0; idx < edges.size() && comps > 1; ++idx){
		tuple<int, int, int> t = edges[idx];
		int u = get<0>(t), v = get<1>(t), w = get<2>(t);
		if(find_parent(parent, u) != find_parent(parent, v)){
			cost += w;
			unite(parent, u, v);
			--comps;
			++edge_cnt;
			added.push_back(make_tuple(u, v));
		}
	}
	cout << cost << ' ' << edge_cnt << '\n';
	for(tuple<int, int> edge : added){
		cout << get<0>(edge) << ' ' << get<1>(edge) << '\n';
	}
	return 0;
}
