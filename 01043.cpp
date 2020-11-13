#include <cstdio>
#include <queue>
#define MAX (50 + 1)

void bfs(bool adj[][MAX], bool knows[MAX], int n){
	int visited[MAX] = {};
	std::queue<int> q;
	for(int i = 1; i <= n; ++i){
		if(knows[i]){
			visited[i] = true;
			q.push(i);
		}
	}
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int j = 1; j <= n; ++j){
			if(adj[x][j] && !visited[j]){
				visited[j] = true;
				knows[j] = true;
				q.push(j);
			}
		}
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	bool knows[MAX] = {};
	int num;
	scanf("%d", &num);
	for(int a0 = 0; a0 < num; ++a0){
		int person;
		scanf("%d", &person);
		knows[person] = true;
	}
	bool adj[MAX][MAX] = {};
	int p[MAX][MAX], members[MAX];
	for(int party = 0; party < m; ++party){
		scanf("%d", &members[party]);
		for(int i = 0; i < members[party]; ++i){
			scanf("%d", &p[party][i]);
			for(int j = 0; j < i; ++j){
				adj[p[party][j]][p[party][i]] = true;
				adj[p[party][i]][p[party][j]] = true;
			}
		}
	}
	bfs(adj, knows, n);
	int ans = 0;
	for(int party = 0; party < m; ++party){
		if(members[party] == 0 || !knows[p[party][0]]){
			++ans;
		}
	}
	printf("%d", ans);
	return 0;
}
