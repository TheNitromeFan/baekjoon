#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXX 19

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int col[5], x, y;
		for(int j = 0; j < 5; ++j){
			scanf("%d", &col[j]);
		}
		scanf("%d %d", &x, &y);
		char board[MAXX][5][6];
		for(int i = 0; i < 5; ++i){
			for(int c = 0; c < x; ++c){
				scanf("%s", board[c][i]);
			}
		}
		int ans = 25;
		vector<int> bitmask(y, 1);
		bitmask.resize(x);
		do{
			char pattern[5][6];
			for(int i = 0; i < 5; ++i){
				for(int j = 0; j < 5; ++j){
					pattern[i][j] = 'O';
				}
			}
			for(int c = 0; c < x; ++c){
				if(bitmask[c]){
					for(int i = 0; i < 5; ++i){
						for(int j = 0; j < 5; ++j){
							if(board[c][i][j] == 'X'){
								pattern[i][j] = 'X';
							}
						}
					}
				}
			}
			int cmp = 0;
			for(int j = 0; j < 5; ++j){
				int cnt = 0;
				for(int i = 0; i < 5; ++i){
					if(pattern[i][j] == 'X' && !(i == 2 && j == 2)){
						++cnt;
					}
				}
				cmp += max(0, cnt - col[j]);
			}
			ans = min(ans, cmp);
		}while(prev_permutation(bitmask.begin(), bitmask.end()));
		printf("%d\n", ans);
	}
	return 0;
}
