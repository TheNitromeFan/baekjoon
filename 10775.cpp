#include <cstdio>
#define MAX (100000 + 1)

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
		parent[px] = py;
	}
}

int planes(int g, int p){
	int parent[MAX];
	for(int i = 0; i <= g; ++i){
		parent[i] = i;
	}
	for(int j = 0; j < p; ++j){
		int x;
		scanf("%d", &x);
		int px = find_parent(parent, x);
		if(px == 0){
			return j;
		}
		unify(parent, px, px - 1);
		// printf("%d\n", find_parent(parent, x));
	}
	return p;
}

int main(){
	int g, p;
	scanf("%d %d", &g, &p);
	printf("%d", planes(g, p));
	return 0;
}
