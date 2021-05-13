#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

void color(vector<vector<int>> &adj, vector<int> &colored, int n, int start){
	queue<int> q;
	q.push(start);
	colored[start] = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : adj[u]){
			if(colored[v] == 0){
				q.push(v);
				colored[v] = 3 - colored[u];
			}
		}
	}
}

int main(){
	FILE *fp = fopen("calvin10.txt", "r");
	int n, m;
	fscanf(fp, "%d %d", &n, &m);
	printf("%d %d\n", n, m);
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < m; ++i){
		int u, v;
		fscanf(fp, "%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	printf("%d\n", 1);
	vector<int> colored(n + 1);
	for(int u = 1; u <= n; ++u){
		if(colored[u] == 0){
			color(adj, colored, n, u);
		}
	}
	FILE *fp1 = fopen("10970.txt", "w");
	fprintf(fp1, "%d\n", 2);
	for(int u = 1; u <= n; ++u){
		if(colored[u] == 1){
			fprintf(fp1, "%d ", u);
		}
	}
	fprintf(fp1, "\n");
	for(int u = 1; u <= n; ++u){
		if(colored[u] == 2){
			fprintf(fp1, "%d ", u);
		}
	}
	fprintf(fp1, "\n");
	fclose(fp);
	fclose(fp1);
	return 0;
}
