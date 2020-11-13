#include <cstdio>
#include <cstdlib>
#include <map>

int board[128][128];

std::map<int, int> counts;

bool all_same(int n, int startx, int starty){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(board[startx+i][starty+j] != board[startx][starty]){
				return false;
			}
		}
	}
	return true;
}

void get_counts(int n, int startx, int starty){
	if(all_same(n, startx, starty)){
		++counts[board[startx][starty]];
		return;
	}
	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < 2; ++j){
			get_counts(n/2, startx + i*n/2, starty + j*n/2);
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			scanf("%d", &board[i][j]);
		}
	}
	counts[0] = 0;
	counts[1] = 0;
	get_counts(n, 0, 0);
	printf("%d\n%d", counts[0], counts[1]);
	return 0;
}
