#include <cstdio>
#include <queue>
#include <utility>
#define LENGTH_MAX 1000
#define ACTION_MAX 20000
#define TIME_MAX 1000000000

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool in_snake(deque<pair<int, int>> &snake, int x, int y){
	for(deque<pair<int, int>>::size_type i = 0; i < snake.size(); ++i){
		if(snake[i].first == x && snake[i].second == y){
			return true;
		}
	}
	return false;
}

int main(){
	// FILE *fp = fopen("D-small-practice.out", "w");
	int t;
	scanf("%d", &t);
	deque<pair<int, int>> snake;
	for(int t0 = 1; t0 <= t; ++t0){
		int r, c, s;
		scanf("%d %d %d", &s, &r, &c);
		bool map[LENGTH_MAX + 1][LENGTH_MAX + 1] = {};
		for(int i = 1; i <= r; ++i){
			for(int j = 1; j <= c; ++j){
				map[i][j] = ((i + j) % 2 == 1);
			}
		}
		pair<int, char> moves[ACTION_MAX] = {};
		for(int m = 0; m < s; ++m){
			scanf("%d %c", &moves[m].first, &moves[m].second);
		}
		snake.clear(); // front: head, back: tail
		snake.push_front(make_pair(1, 1));
		int moves_index = 0;
		int direction = 0;
		int time;
		for(int time = 1; time <= TIME_MAX; ++time){
			pair<int, int> head = snake.front();
			int nx = head.first + dx[direction], ny = head.second + dy[direction];
			if(nx == 0){
				nx = r;
			}else if(nx == r + 1){
				nx = 1;
			}else if(ny == 0){
				ny = c;
			}else if(ny == c + 1){
				ny = 1;
			}
			if(map[nx][ny]){
				map[nx][ny] = false;
			}else{
				snake.pop_back();
			}
			if(in_snake(snake, nx, ny)){
				break;
			}
			snake.push_front(make_pair(nx, ny));
			if(moves_index < s && moves[moves_index].first == time){
				if(moves[moves_index].second == 'R'){
					direction = (direction + 1) % 4;
				}else{
					direction = (direction + 3) % 4;
				}
				++moves_index;
			}
		}
		// fprintf(fp, "Case #%d: %u\n", t0, snake.size() + (time <= TIME_MAX));
		printf("Case #%d: %u\n", t0, snake.size() + (time <= TIME_MAX));
	}
	// fclose(fp);
	return 0;
}
