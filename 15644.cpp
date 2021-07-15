#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#define MAX 11

using namespace std;

int marble(char board[][MAX], int n, int m, int prev_rx[][MAX][MAX][MAX], int prev_ry[][MAX][MAX][MAX], int prev_bx[][MAX][MAX][MAX], int prev_by[][MAX][MAX][MAX], int rx, int ry, int bx, int by, int &frx, int &fry, int &fbx, int &fby){
	int dist[MAX][MAX][MAX][MAX];
	memset(dist, -1, sizeof(dist));
	queue<int> q;
	bool visited[MAX][MAX][MAX][MAX] = {};
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	dist[rx][ry][bx][by] = 0;
	q.push(rx);
	q.push(ry);
	q.push(bx);
	q.push(by);
	visited[rx][ry][bx][by] = true;
	while(!q.empty()){
		int x1 = q.front();
		q.pop();
		int y1 = q.front();
		q.pop();
		int x2 = q.front();
		q.pop();
		int y2 = q.front();
		q.pop();
		// printf("%d %d %d %d\n", x1, y1, x2, y2);
		if(board[x2][y2] == 'O'){
			continue;
		}else if(board[x1][y1] == 'O'){
			frx = x1;
			fry = y1;
			fbx = x2;
			fby = y2;
			return dist[x1][y1][x2][y2];
		}
		for(int i = 0; i < 4; ++i){
			int nx1 = x1, ny1 = y1, nx2 = x2, ny2 = y2;
			bool red_hole = false, blue_hole = false;
			while(true){
				int tmp1 = nx1 + dx[i];
				int tmp2 = ny1 + dy[i];
				int tmp3 = nx2 + dx[i];
				int tmp4 = ny2 + dy[i];
				if(red_hole || board[tmp1][tmp2] == '#' || (!blue_hole && tmp1 == nx2 && tmp2 == ny2)){
					tmp1 = nx1;
					tmp2 = ny1;
				}
				if(blue_hole || board[tmp3][tmp4] == '#' || (!red_hole && tmp3 == nx1 && tmp4 == ny1)){
					tmp3 = nx2;
					tmp4 = ny2;
				}
				if(tmp1 == nx1 && tmp2 == ny1 && tmp3 == nx2 && tmp4 == ny2){
					break;
				}
				nx1 = tmp1;
				ny1 = tmp2;
				nx2 = tmp3;
				ny2 = tmp4;
				if(board[nx1][ny1] == 'O'){
					red_hole = true;
				}
				if(board[nx2][ny2] == 'O'){
					blue_hole = true;
				}
			}
			if(!visited[nx1][ny1][nx2][ny2] && dist[x1][y1][x2][y2] < 10){
				dist[nx1][ny1][nx2][ny2] = dist[x1][y1][x2][y2] + 1;
				q.push(nx1);
				q.push(ny1);
				q.push(nx2);
				q.push(ny2);
				visited[nx1][ny1][nx2][ny2] = true;
				prev_rx[nx1][ny1][nx2][ny2] = x1;
				prev_ry[nx1][ny1][nx2][ny2] = y1;
				prev_bx[nx1][ny1][nx2][ny2] = x2;
				prev_by[nx1][ny1][nx2][ny2] = y2;
			}
		}
	}
	return -1;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char board[MAX][MAX];
	int redx = -1, redy = -1, bluex = -1, bluey = -1;
	for(int i = 0; i < n; ++i){
		scanf("%s", board[i]);
		for(int j = 0; j < m; ++j){
			if(board[i][j] == 'R'){
				redx = i;
				redy = j;
			}else if(board[i][j] == 'B'){
				bluex = i;
				bluey = j;
			}
		}
	}
	int prev_rx[MAX][MAX][MAX][MAX], prev_ry[MAX][MAX][MAX][MAX], prev_bx[MAX][MAX][MAX][MAX], prev_by[MAX][MAX][MAX][MAX];
	int rx = -1, ry = -1, bx = -1, by = -1;
	int ans = marble(board, n, m, prev_rx, prev_ry, prev_bx, prev_by, redx, redy, bluex, bluey, rx, ry, bx, by);
	printf("%d\n", ans);
	if(ans != -1){
		string moves;
		for(int i = 0; i < ans; ++i){
			int prx = prev_rx[rx][ry][bx][by];
			int pry = prev_ry[rx][ry][bx][by];
			int pbx = prev_bx[rx][ry][bx][by];
			int pby = prev_by[rx][ry][bx][by];
			if(prx <= rx && pry == ry && pbx <= bx && pby == by){
				moves += 'D';
			}else if(prx >= rx && pry == ry && pbx >= bx && pby == by){
				moves += 'U';
			}else if(prx == rx && pry <= ry && pbx == bx && pby <= by){
				moves += 'R';
			}else{
				moves += 'L';
			}
			rx = prx;
			ry = pry;
			bx = pbx;
			by = pby;
		}
		reverse(moves.begin(), moves.end());
		printf("%s\n", moves.c_str());
	}
	return 0;
}
