#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 1; a0 <= t; ++a0){
		int n;
		scanf("%d", &n);
		char dir[6];
		scanf("%s", dir);
		int board[20][20] = {};
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				scanf("%d", &board[i][j]);
			}
		}
		printf("Case #%d:\n", a0);
		int final[20][20] = {};
		if(dir[0] == 'l'){
			for(int i = 0; i < n; ++i){
				int line[20] = {};
				int idx = 0;
				for(int j = 0; j < n; ++j){
					if(board[i][j] != 0){
						line[idx] = board[i][j];
						++idx;
					}
				}
				int k = idx;
				idx = 0;
				for(int j = 0; j < k; ++j){
					if(j + 1 < k && line[j] == line[j + 1]){
						final[i][idx] = 2 * line[j];
						++j;
					}else{
						final[i][idx] = line[j];
					}
					++idx;
				}
			}
		}else if(dir[0] == 'r'){
			for(int i = 0; i < n; ++i){
				int line[20] = {};
				int idx = 0;
				for(int j = n - 1; j >= 0; --j){
					if(board[i][j] != 0){
						line[idx] = board[i][j];
						++idx;
					}
				}
				int k = idx;
				idx = n - 1;
				for(int j = 0; j < k; ++j){
					if(j + 1 < k && line[j] == line[j + 1]){
						final[i][idx] = 2 * line[j];
						++j;
					}else{
						final[i][idx] = line[j];
					}
					--idx;
				}
			}
		}else if(dir[0] == 'u'){
			for(int j = 0; j < n; ++j){
				int line[20] = {};
				int idx = 0;
				for(int i = 0; i < n; ++i){
					if(board[i][j] != 0){
						line[idx] = board[i][j];
						++idx;
					}
				}
				int k = idx;
				idx = 0;
				for(int i = 0; i < k; ++i){
					if(i + 1 < k && line[i] == line[i + 1]){
						final[idx][j] = 2 * line[i];
						++i;
					}else{
						final[idx][j] = line[i];
					}
					++idx;
				}
			}
		}else if(dir[0] == 'd'){
			for(int j = 0; j < n; ++j){
				int line[20] = {};
				int idx = 0;
				for(int i = n - 1; i >= 0; --i){
					if(board[i][j] != 0){
						line[idx] = board[i][j];
						++idx;
					}
				}
				int k = idx;
				idx = n - 1;
				for(int i = 0; i < k; ++i){
					if(i + 1 < k && line[i] == line[i + 1]){
						final[idx][j] = 2 * line[i];
						++i;
					}else{
						final[idx][j] = line[i];
					}
					--idx;
				}
			}
		}
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				printf("%d ", final[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
