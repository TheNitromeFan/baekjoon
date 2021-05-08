#include <cstdio>
#include <vector>
#include <queue>
#define MAX 32

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int dist(char map[][MAX], int h, int w, int sx, int sy, int fx, int fy){
	bool visited[MAX][MAX] = {};
	queue<int> q;
	q.push(sx);
	q.push(sy);
	q.push(0);
	visited[sx][sy] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		int d = q.front();
		q.pop();
		if(x == fx && y == fy){
			return d;
		}else if(map[x][y] == 'R' && !(x == sx && y == sy)){
			continue;
		}
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < h && ny >= 0 && ny < w
			&& map[nx][ny] != 'X' && !visited[nx][ny]){
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
	int t;
	scanf("%d", &t);
	for(int a0 = 1; a0 <= t; ++a0){
		int h, w;
		scanf("%d %d", &h, &w);
		char map[MAX][MAX];
		vector<int> startx, starty, meetx, meety, restx, resty;
		for(int i = 0; i < h; ++i){
			scanf("%s", map[i]);
			for(int j = 0; j < w; ++j){
				if(map[i][j] == 'S'){
					startx.push_back(i);
					starty.push_back(j);
				}else if(map[i][j] == 'M'){
					meetx.push_back(i);
					meety.push_back(j);
				}else if(map[i][j] == 'R'){
					restx.push_back(i);
					resty.push_back(j);
				}
			}
		}
		int min_dist = -1;
		for(unsigned m = 0; m < meetx.size(); ++m){
			for(unsigned r = 0; r < restx.size(); ++r){
				int mx = meetx[m], my = meety[m], rx = restx[r], ry = resty[r];
				int sum = 0;
				int dist2 = dist(map, h, w, mx, my, rx, ry);
				if(dist2 == -1){
					continue;
				}else{
					sum += (int)startx.size() * dist2;
				}
				bool good = true;
				for(unsigned s = 0; s < startx.size(); ++s){
					int sx = startx[s], sy = starty[s];
					int dist1 = dist(map, h, w, sx, sy, mx, my);
					int dist3 = dist(map, h, w, rx, ry, sx, sy);
					// printf("%d %d %d %d %d %d, dist1 = %d, dist3 = %d\n", sx, sy, mx, my, rx, ry, dist1, dist3);
					if(dist1 == -1 || dist3 == -1){
						good = false;
						break;
					}else{
						sum += dist1 + dist3;
					}
				}
				if(good && (min_dist == -1 || min_dist > sum)){
					min_dist = sum;
				}
			}
		}
		printf("Data Set %d:\n", a0);
		if(min_dist == -1){
			printf("Impossible\n");
		}else{
			printf("%d\n", min_dist);
		}
	}
	return 0;
}
