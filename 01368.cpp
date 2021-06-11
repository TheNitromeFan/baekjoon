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
	return weight;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<tuple<int, int, int>> edges;
	for(int u = 1; u <= n; ++u){
		int w;
		cin >> w;
		edges.push_back(make_tuple(0, u, w));
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			int w;
			cin >> w;
			if(j < i){
				edges.push_back(make_tuple(j, i, w));
			}
		}
	}
	cout << minimum_spanning_tree(edges, n);
	return 0;
}
