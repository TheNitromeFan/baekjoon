#include <cstdio>
#define MAX (1000 + 1)

void euler_cycle(int adj[][MAX], int n, int v){
	for(int i = 1; i <= n; ++i){
		while(adj[v][i]){
			--adj[v][i];
			--adj[i][v];
			euler_cycle(adj, n, i);
		}
	}
	printf("%d ", v);
}

int main(){
	int n;
	scanf("%d", &n);
	static int adj[MAX][MAX];
	bool euler = true;
	for(int i = 1; i <= n; ++i){
		int cnt = 0;
		for(int j = 1; j <= n; ++j){
			scanf("%d", &adj[i][j]);
			cnt += adj[i][j];
		}
		if(cnt % 2 == 1){
			euler = false;
		}
	}
	if(euler){
		euler_cycle(adj, n, 1);
	}else{
		printf("-1");
	}
	return 0;
}
