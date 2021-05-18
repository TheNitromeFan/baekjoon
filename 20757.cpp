#include <iostream>
#include <vector>
#include <utility>

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

int roads(vector<pair<int, int>> &edges, int nt){
	vector<int> parent(nt + 1);
	for(int v = 1; v <= nt; ++v){
		parent[v] = v;
	}
	int cnt = 0;
	for(pair<int, int> edge : edges){
		int u = edge.first, v = edge.second;
		if(find_parent(parent, u) != find_parent(parent, v)){
			++cnt;
			unite(parent, u, v);
		}
	}
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int nt;
		cin >> nt;
		vector<pair<int, int>> edges;
		for(int u = 1; u <= nt; ++u){
			for(int v = 1; v <= nt; ++v){
				int x;
				cin >> x;
				if(u < v && x){
					edges.push_back(make_pair(u, v));
				}
			}
		}
		cout << roads(edges, nt) << '\n';
	}
	return 0;
}
