#include <cstdio>
#define MAX 1000000

int find_parent(int parent[MAX+1], int x){
	if(x == parent[x]){
		return x;
	}else{
		parent[x] = find_parent(parent, parent[x]);
		return parent[x];
	}
}

void unite(int parent[MAX+1], int x, int y){
	x = find_parent(parent, x);
	y = find_parent(parent, y);
	if(x != y){
		parent[y] = x;
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	static int parent[MAX+1];
	for(int i = 0; i <= MAX; ++i){
		parent[i] = i;
	}
	int q, a, b;
	while(scanf("%d %d %d", &q, &a, &b) == 3){
		if(q == 0){
			unite(parent, a, b);
		}else if(q == 1){
			printf("%s\n", (find_parent(parent, a) == find_parent(parent, b) ? "YES" : "NO"));
		}
	}
	return 0;
}
