#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <functional>

using namespace std;

int find_parent(vector<int> &parent, int x){
	if(parent[x] == x){
		return x;
	}
	parent[x] = find_parent(parent, parent[x]);
	return parent[x];
}

void unite(vector<int> &parent, int x, int y){
	int px = find_parent(parent, x);
	int py = find_parent(parent, y);
	parent[py] = px;
}

int blue_count1(vector<tuple<char, int, int>> &edges, int n){
	sort(edges.begin(), edges.end());
	vector<int> parent(n + 1);
	for(int u = 1; u <= n; ++u){
		parent[u] = u;
	}
	int ret = 0;
	for(tuple<char, int, int> edge : edges){
		char color = get<0>(edge);
		int u = get<1>(edge), v = get<2>(edge);
		if(find_parent(parent, u) != find_parent(parent, v)){
			unite(parent, u, v);
			if(color == 'B'){
				++ret;
			}
		}
	}
	return ret;
}

int blue_count2(vector<tuple<char, int, int>> &edges, int n){
	sort(edges.begin(), edges.end(), greater<tuple<char, int, int>>());
	vector<int> parent(n + 1);
	for(int u = 1; u <= n; ++u){
		parent[u] = u;
	}
	int ret = 0;
	for(tuple<char, int, int> edge : edges){
		char color = get<0>(edge);
		int u = get<1>(edge), v = get<2>(edge);
		if(find_parent(parent, u) != find_parent(parent, v)){
			unite(parent, u, v);
			if(color == 'B'){
				++ret;
			}
		}
	}
	return ret;
}

bool red_blue(vector<tuple<char, int, int>> &edges, int n, int k){
	return blue_count1(edges, n) >= k && blue_count2(edges, n) <= k;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n, m, k;
		cin >> n >> m >> k;
		if(n == 0 && m == 0 && k == 0){
			break;
		}
		vector<tuple<char, int, int>> edges(m);
		for(int i = 0; i < m; ++i){
			char color;
			int u, v;
			cin >> color >> u >> v;
			edges[i] = make_tuple(color, u, v);
		}
		cout << red_blue(edges, n, k) << '\n';
	}
	return 0;
}
