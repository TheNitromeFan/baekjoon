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

int minimum_spanning_tree(vector<tuple<int, int, int>> &edges, int n){
	sort(edges.begin(), edges.end(), [](tuple<int, int, int> a, tuple<int, int, int> b){
		return get<2>(a) < get<2>(b);
	});
	vector<int> parent(n + 1);
	for(int i = 0; i <= n; ++i){
		parent[i] = i;
	}
	int edge_cnt = 0;
	int weight = 0;
	for(tuple<int, int, int> edge : edges){
		int u = get<0>(edge), v = get<1>(edge), w = get<2>(edge);
		if(find_parent(parent, u) != find_parent(parent, v)){
			unite(parent, u, v);
			++edge_cnt;
			weight += w;
			if(edge_cnt == n){
				break;
			}
		}
	}
	return weight * weight;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, int>> edges1(m + 1), edges2(m + 1);
	for(int i = 0; i <= m; ++i){
		int a, b, c;
		cin >> a >> b >> c;
		edges1[i] = make_tuple(a, b, !c);
		edges2[i] = make_tuple(a, b, -(!c));
	}
	int min_cost = minimum_spanning_tree(edges1, n);
	int max_cost = minimum_spanning_tree(edges2, n);
	cout << max_cost - min_cost;
	return 0;
}
