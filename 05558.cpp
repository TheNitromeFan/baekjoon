#include <cstdio>
#include <deque>
#include <utility>

using namespace std;

int bfs(int graph[][1000], int h, int w, pair<int, int> start, pair<int, int> end){
	int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
	static bool visited[1000][1000];
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			visited[i][j] = false;
		}
	}
	deque<int> queue;
	queue.push_back(start.first);
	queue.push_back(start.second);
	queue.push_back(0);
	visited[start.first][start.second] = true;
	int x, y, v;
	while(true){
		x = queue[0];
		queue.pop_front();
		y = queue[0];
		queue.pop_front();
		v = queue[0];
		queue.pop_front();
		for(int i = 0; i < 4; ++i){
			if(x+dx[i] >= 0 && x+dx[i] < h && y+dy[i] >= 0 && y+dy[i] < w 
			&& graph[x+dx[i]][y+dy[i]] != 'X' && !visited[x+dx[i]][y+dy[i]]){
				queue.push_back(x+dx[i]);
				queue.push_back(y+dy[i]);
				queue.push_back(v+1);
				visited[x+dx[i]][y+dy[i]] = true;
				if(x+dx[i] == end.first && y+dy[i] == end.second){
					return v+1;
				}
			}
		}
	}
}

int main(){
	int h, w, n;
	scanf("%d %d %d", &h, &w, &n);
	static int board[1000][1000];
	pair<int, int> points[10];
	char s[1001];
	for(int i = 0; i < h; ++i){
		scanf("%s", s);
		for(int j = 0; j < w; ++j){
			board[i][j] = s[j];
			if(board[i][j] == 'S'){
				points[0] = make_pair(i, j);
			}else if(board[i][j] != '.' && board[i][j] != 'X'){
				points[board[i][j] - '0'] = make_pair(i, j);
			}
		}
	}
	int distance = 0;
	for(int i = 0; i < n; ++i){
		distance += bfs(board, h, w, points[i], points[i+1]);
	}
	printf("%d", distance);
	return 0;
}
