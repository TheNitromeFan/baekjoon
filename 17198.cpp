#include <cstdio>
#include <queue>

using std::queue;

int chain(int bx, int by, int lx, int ly, int rx, int ry){
	queue<int> q;
	bool visited[11][11] = {};
	q.push(lx);
	q.push(ly);
	q.push(0);
	visited[lx][ly] = true;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		int d = q.front();
		q.pop();
		if(x == bx && y == by){
			return d - 1;
		}else if(x == rx && y == ry){
			continue;
		}
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < 10 && ny >= 0 && ny < 10 && !visited[nx][ny]){
				q.push(nx);
				q.push(ny);
				q.push(d + 1);
				visited[nx][ny] = true;
			}
		}
	}
	return -1;
}

int main(){
	char map[11][11];
	int bx = -1, by = -1, lx = -1, ly = -1, rx = -1, ry = -1;
	for(int i = 0; i < 10; ++i){
		scanf("%s", map[i]);
		for(int j = 0; j < 10; ++j){
			if(map[i][j] == 'B'){
				bx = i;
				by = j;
			}else if(map[i][j] == 'L'){
				lx = i;
				ly = j;
			}else if(map[i][j] == 'R'){
				rx = i;
				ry = j;
			}
		}
	}
	printf("%d", chain(bx, by, lx, ly, rx, ry));
	return 0;
}
