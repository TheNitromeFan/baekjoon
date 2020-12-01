#include <cstdio>
#include <cstring>
#include <queue>

using std::queue;

bool win(char s[][100001], int n, int k, int sx, int sy, int time){
	queue<int> q;
	int visited[2][200001];
	memset(visited, -1, sizeof(visited));
	q.push(sx);
	q.push(sy);
	q.push(time);
	visited[sy][sx] = time;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		int t = q.front();
		q.pop();
		if(x >= n){
			return true;
		}
		if(s[y][x] == '0'){
			continue;
		}
		if(visited[y][x + 1] == -1){
			q.push(x + 1);
			q.push(y);
			q.push(t + 1);
			visited[y][x + 1] = t + 1;
		}
		if(x - 1 > t && visited[y][x - 1] == -1){
			q.push(x - 1);
			q.push(y);
			q.push(t + 1);
			visited[y][x - 1] = t + 1;
		}
		if(visited[1 - y][x + k] == -1){
			q.push(x + k);
			q.push(1 - y);
			q.push(t + 1);
			visited[1 - y][x + k] = t + 1;
		}
	}
	return false;
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	char s[2][100001];
	scanf("%s", s[0]);
	scanf("%s", s[1]);
	printf("%d", win(s, n, k, 0, 0, 0));
	return 0;
}
