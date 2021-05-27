#include <iostream>
#include <vector>

using namespace std;

int find_parent(vector<int> &parent, vector<int> &weight, int x){
	if(parent[x] == x){
		return x;
	}else{
		int y = find_parent(parent, weight, parent[x]);
		weight[x] += weight[parent[x]];
		parent[x] = y;
		return parent[x];
	}
}

void unite(vector<int> &parent, vector<int> &weight, int x, int y, int w){
	int px = find_parent(parent, weight, x);
	int py = find_parent(parent, weight, y);
	if(px != py){
		parent[py] = px;
		weight[py] = weight[x] - weight[y] + w;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n, m;
		cin >> n >> m;
		if(n == 0 && m == 0){
			break;
		}
		vector<int> parent(n + 1), weight(n + 1);
		for(int u = 1; u <= n; ++u){
			parent[u] = u;
		}
		for(int i = 0; i < m; ++i){
			char op;
			cin >> op;
			if(op == '!'){
				int a, b, w;
				cin >> a >> b >> w;
				unite(parent, weight, a, b, w);
			}else{
				int a, b;
				cin >> a >> b;
				if(find_parent(parent, weight, a) == find_parent(parent, weight, b)){
					cout << weight[b] - weight[a] << '\n';
				}else{
					cout << "UNKNOWN\n";
				}
			}
		}
	}
	return 0;
}
