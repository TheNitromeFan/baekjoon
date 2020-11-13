#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[501];

int time[501], indegree[501];

int result[501];

void toposort(int n){
	queue<int> q;
	for(int i = 1; i <= n; ++i){
		if(indegree[i] == 0){
			result[i] = time[i];
			q.push(i);
		}
	}
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int u : adj[v]){
			if(result[u] < result[v] + time[u]){
				result[u] = result[v] + time[u];
			}
			--indegree[u];
			if(indegree[u] == 0){
				q.push(u);
			}
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &time[i]);
		int x;
		while(true){
			scanf("%d", &x);
			if(x == -1){
				break;
			}
			adj[x].push_back(i);
			++indegree[i];
		}
	}
	toposort(n);
	for(int i = 1; i <= n; ++i){
		printf("%d\n", result[i]);
	}
	return 0;
}
