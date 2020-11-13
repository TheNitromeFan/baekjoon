#include <cstdio>
#include <queue>

using std::queue;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(queue<int> &q, char map[][200], int r, int c){
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < r && ny >= 0 && ny < c && map[nx][ny] == 'T'){
				map[nx][ny] = 'S';
				q.push(nx);
				q.push(ny);
			}
		}
	}
}

int main(){
	while(true){
		int w, h;
		scanf("%d %d", &w, &h);
		if(w == 0 && h == 0){
			break;
		}
		char forest[200][200];
		queue<int> q;
		for(int i = 0; i < h; ++i){
			scanf("%s", forest[i]);
			for(int j = 0; j < w; ++j){
				if(forest[i][j] == 'S'){
					q.push(i);
					q.push(j);
				}
			}
		}
		bfs(q, forest, h, w);
		for(int i = 0; i < h; ++i){
			for(int j = 0; j < w; ++j){
				printf("%c", forest[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
