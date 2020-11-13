#include <cstdio>
#define MAX (300000 + 1)

int find_parent(int parent[MAX], int x){
	if(parent[x] != x){
		parent[x] = find_parent(parent, parent[x]);
	}
	return parent[x];
}

void merge(int parent[MAX], int x, int y){
	int px = find_parent(parent, x), py = find_parent(parent, y);
	if(px != py){
		parent[px] = py;
	}
}

int main(){
	int n, drawers;
	scanf("%d %d", &n, &drawers);
	int parent[MAX] = {};
	bool visited[MAX] = {};
	for(int x = 1; x <= drawers; ++x){
		parent[x] = x;
	}
	for(int i = 0; i < n; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		int pa = find_parent(parent, parent[a]), pb = find_parent(parent, parent[b]);
		if(!visited[a]){
			visited[a] = true;
			merge(parent, a, b);
			printf("LADICA\n");
		}else if(!visited[b]){
			visited[b] = true;
			merge(parent, b, a);
			printf("LADICA\n");
		}else if(!visited[pa]){
			visited[pa] = true;
			merge(parent, a, b);
			printf("LADICA\n");
		}else if(!visited[pb]){
			visited[pb] = true;
			merge(parent, b, a);
			printf("LADICA\n");
		}else{
			printf("SMECE\n");
		}
	}
	return 0;
}
