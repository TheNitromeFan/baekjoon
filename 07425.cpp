#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void flip_tile(char board[][5], int x, int y){
	if(board[x][y] == 'w'){
		board[x][y] = 'b';
	}else{
		board[x][y] = 'w';
	}
}

bool all_same(char board[][5]){
	for(int i = 0; i < 4; ++i){
		for(int j = 0; j < 4; ++j){
			if(board[i][j] != board[0][0]){
				return false;
			}
		}
	}
	return true;
}

bool valid_flip(char board[][5], vector<int> &flips, int dx[4], int dy[4]){
	for(int flip : flips){
		int x = flip / 4, y = flip % 4;
		flip_tile(board, x, y);
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx >= 0 && nx < 4 && ny >= 0 && ny < 4){
				flip_tile(board, nx, ny);
			}
		}
	}
	return all_same(board);
}

int main(){
	char board[4][5];
	for(int i = 0; i < 4; ++i){
		scanf("%s", board[i]);
	}
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	for(int flips = 0; flips <= 16; ++flips){
		vector<int> bitmask(flips, 1);
		bitmask.resize(16, 0);
		do{
			char board_copy[4][5];
			for(int i = 0; i < 4; ++i){
				for(int j = 0; j < 4; ++j){
					board_copy[i][j] = board[i][j];
				}
			}
			vector<int> v;
			for(int i = 0; i < 16; ++i){
				if(bitmask[i]){
					v.push_back(i);
				}
			}
			if(valid_flip(board_copy, v, dx, dy)){
				printf("%d", flips);
				return 0;
			}
		}while(prev_permutation(bitmask.begin(), bitmask.end()));
	}
	printf("Impossible");
	return 0;
}
