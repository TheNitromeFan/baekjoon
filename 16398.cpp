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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<tuple<int, int, int>> edges;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			int cij;
			cin >> cij;
			if(j < i){
				edges.push_back(make_tuple(j, i, cij));
			}
		}
	}
	sort(edges.begin(), edges.end(), [](tuple<int, int, int> a, tuple<int, int, int> b){
		return get<2>(a) < get<2>(b);
	});
	vector<int> parent(n);
	for(int u = 0; u < n; ++u){
		parent[u] = u;
	}
	long long cost = 0;
	int edge_cnt = 0;
	for(tuple<int, int, int> edge : edges){
		int u = get<0>(edge), v = get<1>(edge), c = get<2>(edge);
		if(find_parent(parent, u) != find_parent(parent, v)){
			unite(parent, u, v);
			cost += c;
			++edge_cnt;
			if(edge_cnt == n - 1){
				break;
			}
		}
	}
	cout << cost;
	return 0;
}
