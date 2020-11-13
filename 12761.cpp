#include <cstdio>
#include <queue>
#define MAX (100000 + 1)

using namespace std;

int bfs(int a, int b, int start, int end){
	queue<int> q;
	q.push(start);
	int visited[MAX] = {};
	int dx[3] = {1, a, b};
	while(!q.empty()){
		int x = q.front();
		q.pop();
		if(x == end){
			return visited[x];
		}
		for(int i = 0; i < 3; ++i){
			int nx;
			nx = x - dx[i];
			if(nx >= 0 && nx != start && visited[nx] == 0){
				q.push(nx);
				visited[nx] = visited[x] + 1;
			}
			nx = x + dx[i];
			if(nx <= MAX && nx != start && visited[nx] == 0){
				q.push(nx);
				visited[nx] = visited[x] + 1;
			}
			nx = x * dx[i];
			if(nx <= MAX && nx != start && visited[nx] == 0){
				q.push(nx);
				visited[nx] = visited[x] + 1;
			}
		}
	}
	return -1;
}

int main(){
	int n, m, a, b;
	scanf("%d %d %d %d", &a, &b, &n, &m);
	printf("%d", bfs(a, b, n, m));
	return 0;
}
