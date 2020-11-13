#include <cstdio>
#define MAX (200 + 1)

int find_parent(int parent[MAX], int x){
	if(parent[x] == x){
		return x;
	}else{
		parent[x] = find_parent(parent, parent[x]);
	}
	return parent[x];
}

void unify(int parent[MAX], int x, int y){
	int px = find_parent(parent, x), py = find_parent(parent, y);
	if(px != py){
		parent[py] = px;
	}
}

bool can_travel(int parent[MAX], int m){
	int x;
	scanf("%d", &x);
	int px = find_parent(parent, x);
	for(int i = 1; i < m; ++i){
		int y;
		scanf("%d", &y);
		if(px != find_parent(parent, y)){
			return false;
		}
	}
	return true;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int adj[MAX][MAX];
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			scanf("%d", &adj[i][j]);
		}
	}
	int parent[MAX];
	for(int i = 1; i <= n; ++i){
		parent[i] = i;
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j < i; ++j){
			if(adj[i][j]){
				unify(parent, i, j);
			}
		}
	}
	printf("%s", can_travel(parent, m) ? "YES" : "NO");
	return 0;
}
