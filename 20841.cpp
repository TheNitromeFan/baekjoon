#include <cstdio>
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
	int px = find_parent(parent, x), py = find_parent(parent, y);
	parent[py] = px;
}

int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	char map[701][701];
	for(int i = 0; i < n; ++i){
		scanf("%s", map[i]);
	}
	vector<int> parent(100);
	for(int c = 'A'; c < 'A' + k; ++c){
		parent[c] = c;
	}
	int ans = k;
	for(int j = 0; j < m; ++j){
		for(int i1 = 0; i1 < n; ++i1){
			for(int i2 = 0; i2 < i1; ++i2){
				if(find_parent(parent, map[i1][j]) != find_parent(parent, map[i2][j])){
					--ans;
					unite(parent, map[i1][j], map[i2][j]);
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}
