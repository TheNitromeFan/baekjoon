#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

char adj[51][51];

int friends(int n, int start){
	queue<pair<int, int>> q;
	q.push({start, 0});
	bool visited[51] = {};
	visited[start] = true;
	int cnt = 0;
	while(!q.empty()){
		pair<int, int> tmp = q.front();
		q.pop();
		++cnt;
		int u = tmp.first;
		int dist = tmp.second;
		if(dist == 2){
			continue;
		}
		for(int v = 0; v < n; ++v){
			if(adj[u][v] == 'Y' && !visited[v]){
				q.push({v, dist+1});
				visited[v] = true;
			}
		}
	}
	return cnt - 1;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%s", adj[i]);
	}
	int mx = 0;
	for(int i = 0; i < n; ++i){
		int tmp = friends(n, i);
		if(tmp > mx){
			mx = tmp;
		}
	}
	printf("%d", mx);
	return 0;
}
