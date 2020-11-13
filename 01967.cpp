#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
#define MAX (10000 + 1)

using namespace std;

bool visited[MAX];
vector<pair<int, int>> graph[MAX];

int diameter;
int farthest_node;

void dfs(int node, int cost){
	if(visited[node]){
		return;
	}
	visited[node] = true;
	if(diameter < cost){
		diameter = cost;
		farthest_node = node;
	}
	for(pair<int, int> p : graph[node]){
		dfs(p.first, cost + p.second);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		graph[u].push_back(make_pair(v, w));
		graph[v].push_back(make_pair(u, w));
	}
	dfs(1, 0);
	memset(visited, false, sizeof(visited));
	diameter = 0;
	dfs(farthest_node, 0);
	printf("%d", diameter);
	return 0;
}
