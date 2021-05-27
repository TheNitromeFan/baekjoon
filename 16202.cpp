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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	vector<pair<int, int>> edges(m + 1);
	for(int i = 1; i <= m; ++i){
		int x, y;
		cin >> x >> y;
		edges[i] = make_pair(x, y);
	}
	vector<int> used(m + 1);
	for(int a0 = 0; a0 < k; ++a0){
		vector<int> parent(n + 1);
		for(int j = 1; j <= n; ++j){
			parent[j] = j;
		}
		int weight = 0, edge_count = 0;
		for(int i = 1; i <= m; ++i){
			if(used[i] == 2){
				continue;
			}
			int x = edges[i].first, y = edges[i].second;
			if(find_parent(parent, x) != find_parent(parent, y)){
				unite(parent, x, y);
				used[i] = 1;
				weight += i;
				++edge_count;
				if(edge_count == n - 1){
					break;
				}
			}
		}
		if(edge_count == n - 1){
			cout << weight << ' ';
		}else{
			cout << 0 << ' ';
		}
		for(int i = 1; i <= m; ++i){
			if(used[i] == 1){
				used[i] = 2;
				break;
			}
		}
	}
	return 0;
}
