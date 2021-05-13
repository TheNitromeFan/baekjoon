#include <cstdio>
#define MAX 27

void floyd_warshall(bool adj[][MAX]){
	for(int k = 0; k < 26; ++k){
		for(int i = 0; i < 26; ++i){
			for(int j = 0; j < 26; ++j){
				if(adj[i][k] && adj[k][j]){
					adj[i][j] = true;
				}
			}
		}
	}
}

int main(){
	int n, m;
	char u, v;
	scanf("%d", &n);
	bool adj[MAX][MAX] = {};
	for(int i = 0; i < n; ++i){
		scanf(" %c is %c", &u, &v);
		adj[u - 'a'][v - 'a'] = true;
	}
	floyd_warshall(adj);
	scanf("%d", &m);
	for(int j = 0; j < m; ++j){
		scanf(" %c is %c", &u, &v);
		printf("%c\n", adj[u - 'a'][v - 'a'] ? 'T' : 'F');
	}
	return 0;
}
