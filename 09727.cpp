#include <cstdio>
#include <cstring>

bool valid(int board[][6]){
	int cnt[10];
	for(int i = 0; i < 6; ++i){
		memset(cnt, 0, sizeof(cnt));
		for(int j = 0; j < 6; ++j){
			++cnt[board[i][j]];
			if(cnt[board[i][j]] > 1){
				return false;
			}
		}
	}
	for(int j = 0; j < 6; ++j){
		memset(cnt, 0, sizeof(cnt));
		for(int i = 0; i < 6; ++i){
			++cnt[board[i][j]];
			if(cnt[board[i][j]] > 1){
				return false;
			}
		}
	}
	for(int box = 0; box < 6; ++box){
		memset(cnt, 0, sizeof(cnt));
		for(int i = 2 * (box / 2); i < 2 * (box / 2) + 2; ++i){
			for(int j = 3 * (box % 2); j < 3 * (box % 2) + 3; ++j){
				++cnt[board[i][j]];
				if(cnt[board[i][j]] > 1){
					return false;
				}
			}
		}
	}
	memset(cnt, 0, sizeof(cnt));
	for(int i = 0, j = 0; i < 6 && j < 6; ++i, ++j){
		++cnt[board[i][j]];
		if(cnt[board[i][j]] > 1){
			return false;
		}
	}
	memset(cnt, 0, sizeof(cnt));
	for(int i = 0, j = 5; i < 6 && j >= 0; ++i, --j){
		++cnt[board[i][j]];
		if(cnt[board[i][j]] > 1){
			return false;
		}
	}
	return true;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int c = 1; c <= t; ++c){
		int board[6][6];
		for(int i = 0; i < 6; ++i){
			for(int j = 0; j < 6; ++j){
				scanf("%d", &board[i][j]);
			}
		}
		printf("Case#%d: %d\n", c, valid(board));
	}
	return 0;
}
