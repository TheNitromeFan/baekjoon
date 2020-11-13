#include <cstdio>
#include <utility>
#include <deque>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

deque<pair<int, int>> snake; // front is head, back is tail
deque<pair<int, char>> turns;

int board[101][101];

bool in_snake(int x, int y){
	for(int i = 0; i < snake.size(); ++i){
		if(snake[i].first == x && snake[i].second == y){
			return true;
		}
	}
	return false;
}

int main(){
	int n;
	scanf("%d", &n);
	int k;
	scanf("%d", &k);
	for(int apple = 0; apple < k; ++apple){
		int x, y;
		scanf("%d %d", &x, &y);
		board[x][y] = 1;
	}
	int l;
	scanf("%d", &l);
	for(int turn = 0; turn < l; ++turn){
		int x;
		char c;
		scanf("%d %c", &x, &c);
		turns.push_back({x, c});
	}
	snake.push_front({1, 1});
	int dir = 0;
	int seconds = 0;
	int turn_index = 0;
	while(true){
		++seconds;
		pair<int, int> tmp = snake.front();
		int new_x = tmp.first + dx[dir], new_y = tmp.second + dy[dir];
		// check for wall or snake
		if(new_x == 0 || new_x == n+1 || new_y == 0 || new_y == n+1 || in_snake(new_x, new_y)){
		    break;
		}
		snake.push_front({new_x, new_y});
		if(board[new_x][new_y] == 0){
			snake.pop_back();
		}else{
			board[new_x][new_y] = 0;
		}
		if(turn_index < turns.size() && turns[turn_index].first == seconds){
			if(turns[turn_index].second == 'D'){
				dir = (dir + 1) % 4;
 			}else{
				dir = (dir + 3) % 4;
			}
			++turn_index;
		}
		/*
		for(pair<int, int> t : snake){
			printf("(%d, %d) ", t.first, t.second);
		}
		printf("\n");
		*/
	}
	printf("%d", seconds);
	return 0;
}
