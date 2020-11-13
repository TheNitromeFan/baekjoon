#include <cstdio>
#include <cstring>
#include <vector>
#define MAX (50 + 1)

using std::vector;

void floyd_warshall(int adj[][MAX], int n){
	for(int k = 1; k <= n; ++k){
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				if(adj[i][k] != -1 && adj[k][j] != -1 && (adj[i][j] == -1 || adj[i][j] > adj[i][k] + adj[k][j])){
					adj[i][j] = adj[i][k] + adj[k][j];
				}
			}
		}
	}
}

int tally(int adj[][MAX], int n, int x){
	int ret = -1;
	for(int i = 1; i <= n; ++i){
		if(adj[x][i] == -1){
			return -1;
		}else if(ret < adj[x][i]){
			ret = adj[x][i];
		}
	}
	return ret;
}

int main(){
	int n;
	scanf("%d", &n);
	int adj[MAX][MAX];
	memset(adj, -1, sizeof(adj));
	for(int i = 1; i <= n; ++i){
		adj[i][i] = 0;
	}
	while(true){
		int u, v;
		scanf("%d %d", &u, &v);
		if(u == -1 && v == -1){
			break;
		}
		adj[u][v] = 1;
		adj[v][u] = 1;
	}
	floyd_warshall(adj, n);
	vector<int> ans;
	int min_score = -1;
	for(int i = 1; i <= n; ++i){
		int score = tally(adj, n, i);
		if(score != -1 && (min_score == -1 || min_score > score)){
			min_score = score;
			ans.clear();
			ans.push_back(i);
		}else if(score != -1 && min_score == score){
			ans.push_back(i);
		}
	}
	printf("%d %llu\n", min_score, ans.size());
	for(int x : ans){
		printf("%d ", x);
	}
	return 0;
}
