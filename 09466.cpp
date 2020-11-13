#include <cstdio>
#include <cstring>
#define MAX (100000 + 1)

void dfs(int choice[MAX], bool visited[MAX], bool cycle[MAX], int node, int &cnt){
	visited[node] = true;
	int next = choice[node];
	if(!visited[next]){
		dfs(choice, visited, cycle, next, cnt);
	}else if(!cycle[next]){
		++cnt;
		for(int i = next; i != node; i = choice[i]){
			++cnt;
		}
	}
	cycle[node] = true;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		scanf("%d", &n);
		int choice[MAX];
		for(int i = 1; i <= n; ++i){
			scanf("%d", &choice[i]);
		}
		int in_cycle = 0;
		bool visited[MAX] = {}, cycle[MAX] = {};
		for(int i = 1; i <= n; ++i){
			if(visited[i]){
				continue;
			}
			dfs(choice, visited, cycle, i, in_cycle);
		}
		printf("%d\n", n - in_cycle);
	}
	return 0;
}
