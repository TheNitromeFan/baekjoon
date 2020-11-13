#include <cstdio>

int next[101];

bool visited[101];

bool cycle[101];

bool dfs(int start, int cur, int &cnt){
	if(visited[cur]){
		return false;
	}
	visited[cur] = true;
	if(start == cur || dfs(start, next[cur], cnt)){
		++cnt;
		cycle[cur] = true;
		return true;
	}
	return false;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &next[i]);
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			visited[j] = cycle[j];
		}
		dfs(i, next[i], ans);
	}
	printf("%d\n", ans);
	for(int i = 1; i <= n; ++i){
		if(cycle[i]){
			printf("%d\n", i);
		}
	}
	return 0;
}
