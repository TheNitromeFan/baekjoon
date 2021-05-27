#include <iostream>
#include <vector>

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

bool euler_path(vector<int> &degree, int v){
	int odd = 0;
	for(int i = 1; i <= v; ++i){
		if(degree[i] % 2 == 1){
			++odd;
		}
	}
	return odd == 0 || odd == 2;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int v, e;
	cin >> v >> e;
	vector<int> degree(v + 1);
	vector<int> parent(v + 1);
	for(int u = 1; u <= v; ++u){
		parent[u] = u;
	}
	int comps = v;
	for(int i = 0; i < e; ++i){
		int va, vb;
		cin >> va >> vb;
		++degree[va];
		++degree[vb];
		if(find_parent(parent, va) != find_parent(parent, vb)){
			unite(parent, va, vb);
			--comps;
		}
	}
	cout << (comps == 1 && euler_path(degree, v) ? "YES" : "NO");
	return 0;
}
