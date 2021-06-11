#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <algorithm>

using namespace std;

int dist(pair<int, int> p1, pair<int, int> p2){
	return (p2.first - p1.first) * (p2.first - p1.first) + (p2.second - p1.second) * (p2.second - p1.second);
}

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

int irrigation(vector<tuple<int, int, int>> &edges, int n){
	vector<int> parent(n);
	for(int i = 0; i < n; ++i){
		parent[i] = i;
	}
	int comps = n;
	sort(edges.begin(), edges.end(), [](tuple<int, int, int> a, tuple<int, int, int> b){
		return get<2>(a) < get<2>(b);
	});
	int ret = 0;
	for(tuple<int, int, int> edge : edges){
		int u = get<0>(edge), v = get<1>(edge), w = get<2>(edge);
		if(find_parent(parent, u) != find_parent(parent, v)){
			unite(parent, u, v);
			--comps;
			ret += w;
			if(comps == 1){
				break;
			}
		}
	}
	return comps == 1 ? ret : -1;
}

int main(){
	int n, c;
	cin >> n >> c;
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i].first >> v[i].second;
	}
	vector<tuple<int, int, int>> edges;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < i; ++j){
			int d = dist(v[j], v[i]);
			if(d >= c){
				edges.push_back(make_tuple(j, i, d));
			}
		}
	}
	cout << irrigation(edges, n);
	return 0;
}
