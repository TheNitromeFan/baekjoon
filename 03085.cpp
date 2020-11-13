#include <cstdio>
#include <algorithm>
#define MAX (50 + 1)

using std::swap;

int combo(char board[][MAX], int n){
	int ret = 0;
	for(int i = 0; i < n; ++i){
		int cnt = 1;
		for(int j = 1; j < n; ++j){
			if(board[i][j] == board[i][j - 1]){
				++cnt;
			}else{
				cnt = 1;
			}
			if(ret < cnt){
				ret = cnt;
			}
		}
		if(ret < cnt){
			ret = cnt;
		}
	}
	for(int j = 0; j < n; ++j){
		int cnt = 1;
		for(int i = 1; i < n; ++i){
			if(board[i][j] == board[i - 1][j]){
				++cnt;
			}else{
				cnt = 1;
			}
			if(ret < cnt){
				ret = cnt;
			}
		}
		if(ret < cnt){
			ret = cnt;
		}
	}
	return ret;
}

int main(){
	int n;
	scanf("%d", &n);
	char board[MAX][MAX];
	for(int i = 0; i < n; ++i){
		scanf("%s", board[i]);
	}
	int max = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n - 1; ++j){
			if(board[i][j] == board[i][j + 1]){
				continue;
			}
			swap(board[i][j], board[i][j + 1]);
			int cmp = combo(board, n);
			if(max < cmp){
				max = cmp;
			}
			swap(board[i][j], board[i][j + 1]);
		}
	}
	for(int j = 0; j < n; ++j){
		for(int i = 0; i < n - 1; ++i){
			if(board[i][j] == board[i + 1][j]){
				continue;
			}
			swap(board[i][j], board[i + 1][j]);
			int cmp = combo(board, n);
			if(max < cmp){
				max = cmp;
			}
			swap(board[i][j], board[i + 1][j]);
		}
	}
	printf("%d", max);
	return 0;
}
