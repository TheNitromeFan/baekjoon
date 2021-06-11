#include <cstdio>
#include <queue>
#define MAX 1001

using namespace std;

int bfs(queue<int> &q, int map[MAX][MAX], int h, int w){
	int ret = 0;
	int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
	int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
	while(true){
		unsigned sz = q.size() / 2;
		for(unsigned i = 0; i < sz; ++i){
			int x = q.front();
			q.pop();
			int y = q.front();
			q.pop();
			for(int i = 0; i < 8; ++i){
				int nx = x + dx[i];
				int ny = y + dy[i];
				if(nx >= 0 && nx < h && ny >= 0 && ny < w && map[nx][ny] > 0){
					--map[nx][ny];
					if(map[nx][ny] == 0){
						q.push(nx);
						q.push(ny);
					}
				}
			}
		}
		if(q.empty()){
			break;
		}
		++ret;
	}
	return ret;
}

int main(){
	int h, w;
	scanf("%d %d", &h, &w);
	int map[MAX][MAX];
	queue<int> q;
	for(int i = 0; i < h; ++i){
		char line[MAX];
		scanf("%s", line);
		for(int j = 0; j < w; ++j){
			if(line[j] == '.'){
				map[i][j] = 0;
				q.push(i);
				q.push(j);
			}else{
				map[i][j] = line[j] - '0';
			}
		}
	}
	printf("%d", bfs(q, map, h, w));
	return 0;
}
