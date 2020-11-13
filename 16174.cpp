#include <cstdio>
#include <queue>
#define MAX (64 + 1)

bool jelly(int map[][MAX], int n){
	bool visited[MAX][MAX] = {};
	std::queue<int> q;
	q.push(1);
	q.push(1);
	visited[1][1] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		if(x == n && y == n){
			return true;
		}
		int d = map[x][y];
		if(x + d <= n && !visited[x + d][y]){
			q.push(x + d);
			q.push(y);
			visited[x + d][y] = true;
		}
		if(y + d <= n && !visited[x][y + d]){
			q.push(x);
			q.push(y + d);
			visited[x][y + d] = true;
		}
	}
	return false;
}

int main(){
	int n;
	scanf("%d", &n);
	int map[MAX][MAX];
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	printf("%s", jelly(map, n) ? "HaruHaru" : "Hing");
	return 0;
}
