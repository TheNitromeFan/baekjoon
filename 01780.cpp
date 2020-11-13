#include <cstdio>
#include <cstdlib>
#include <map>

int board[2187][2187];

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
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			get_counts(n/3, startx + i*n/3, starty + j*n/3);
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
	counts[-1] = 0;
	counts[0] = 0;
	counts[1] = 0;
	get_counts(n, 0, 0);
	printf("%d\n%d\n%d", counts[-1], counts[0], counts[1]);
	return 0;
}
