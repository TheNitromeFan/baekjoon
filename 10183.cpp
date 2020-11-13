#include <cstdio>
#include <cstring>
#include <deque>
#include <utility>

using namespace std;

int snake_game(char board[][22], char moves[22], deque<pair<int, int>> &snake){
	char direction = 'R';
	int cnt = 0;
	for(int i = 0; i < 20; ++i){
		auto head = snake.front();
		auto tail = snake.back();
		char new_d = moves[i];
		int nx, ny;
		if(new_d == 'O'){
			new_d = direction;
		}
		if(new_d == 'R'){
			nx = head.first;
			ny = head.second + 1;
		}else if(new_d == 'U'){
			nx = head.first - 1;
			ny = head.second;
		}else if(new_d == 'L'){
			nx = head.first;
			ny = head.second - 1;
		}else if(new_d == 'D'){
			nx = head.first + 1;
			ny = head.second;
		}
		direction = new_d;
		if(nx < 0 || nx >= 15 || ny < 0 || ny >= 15){
			board[tail.first][tail.second] = ' ';
			snake.pop_back();
			return -1;
		}else if(board[nx][ny] == 'F'){
			++cnt;
		}else{
			board[tail.first][tail.second] = ' ';
			snake.pop_back();
		}
		board[nx][ny] = 'X';
		snake.push_front(make_pair(nx, ny));
	}
	return cnt;
}

int main(){
	char start[22][22];
	for(int i = 0; i < 15; ++i){
		fgets(start[i], 20, stdin);
	}
	int n;
	scanf("%d", &n);
	deque<pair<int, int>> snake;
	for(int a0 = 0; a0 < n; ++a0){
		char board[22][22] = {};
		snake.clear();
		for(int i = 0; i < 15; ++i){
			for(int j = 0; j < 15; ++j){
				board[i][j] = start[i][j];
				if(board[i][j] == 'X'){
					snake.push_front(make_pair(i, j));
				}
			}
		}
		char moves[22] = {};
		scanf("%s", moves);
		int pellets = snake_game(board, moves, snake);
		if(pellets == -1){
			printf("GAME OVER\n");
		}else{
			printf("%d pellets\n", pellets);
		}
		for(int i = 0; i < 15; ++i){
			for(int j = 0; j < 15; ++j){
				printf("%c", board[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
