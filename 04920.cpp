#include <iostream>
#define MAX 100

using namespace std;

int tetris(int grid[][MAX], int n){
	int ret = -1000000000;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j + 3 < n; ++j){
			int cmp = grid[i][j] + grid[i][j + 1] + grid[i][j + 2] + grid[i][j + 3];
			if(ret < cmp){
				ret = cmp;
			}
		}
	}
	for(int i = 0; i + 3 < n; ++i){
		for(int j = 0; j < n; ++j){
			int cmp = grid[i][j] + grid[i + 1][j] + grid[i + 2][j] + grid[i + 3][j];
			if(ret < cmp){
				ret = cmp;
			}
		}
	}
	for(int i = 0; i + 1 < n; ++i){
		for(int j = 0; j + 2 < n; ++j){
			int cmp = grid[i][j] + grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 1][j + 2];
			if(ret < cmp){
				ret = cmp;
			}
		}
	}
	for(int i = 0; i + 2 < n; ++i){
		for(int j = 0; j + 1 < n; ++j){
			int cmp = grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 1][j] + grid[i + 2][j];
			if(ret < cmp){
				ret = cmp;
			}
		}
	}
	for(int i = 0; i + 1 < n; ++i){
		for(int j = 0; j + 2 < n; ++j){
			int cmp = grid[i][j] + grid[i][j + 1] + grid[i][j + 2] + grid[i + 1][j + 2];
			if(ret < cmp){
				ret = cmp;
			}
		}
	}
	for(int i = 0; i + 2 < n; ++i){
		for(int j = 0; j + 1 < n; ++j){
			int cmp = grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1] + grid[i + 2][j];
			if(ret < cmp){
				ret = cmp;
			}
		}
	}
	for(int i = 0; i + 1 < n; ++i){
		for(int j = 0; j + 2 < n; ++j){
			int cmp = grid[i][j] + grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2];
			if(ret < cmp){
				ret = cmp;
			}
		}
	}
	for(int i = 0; i + 2 < n; ++i){
		for(int j = 0; j + 1 < n; ++j){
			int cmp = grid[i][j + 1] + grid[i][j] + grid[i + 1][j] + grid[i + 2][j];
			if(ret < cmp){
				ret = cmp;
			}
		}
	}
	for(int i = 0; i + 1 < n; ++i){
		for(int j = 0; j + 2 < n; ++j){
			int cmp = grid[i][j] + grid[i][j + 1] + grid[i][j + 2] + grid[i + 1][j + 1];
			if(ret < cmp){
				ret = cmp;
			}
		}
	}
	for(int i = 0; i + 2 < n; ++i){
		for(int j = 0; j + 1 < n; ++j){
			int cmp = grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1] + grid[i + 1][j];
			if(ret < cmp){
				ret = cmp;
			}
		}
	}
	for(int i = 0; i + 1 < n; ++i){
		for(int j = 0; j + 2 < n; ++j){
			int cmp = grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2] + grid[i][j + 1];
			if(ret < cmp){
				ret = cmp;
			}
		}
	}
	for(int i = 0; i + 2 < n; ++i){
		for(int j = 0; j + 1 < n; ++j){
			int cmp = grid[i][j] + grid[i + 1][j] + grid[i + 2][j] + grid[i + 1][j + 1];
			if(ret < cmp){
				ret = cmp;
			}
		}
	}
	for(int i = 0; i + 1 < n; ++i){
		for(int j = 0; j + 1 < n; ++j){
			int cmp = grid[i][j] + grid[i][j + 1] + grid[i + 1][j] + grid[i + 1][j + 1];
			if(ret < cmp){
				ret = cmp;
			}
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k = 0;
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		++k;
		int grid[MAX][MAX];
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				cin >> grid[i][j];
			}
		}
		cout << k << ". " << tetris(grid, n) << "\n";
	}
	return 0;
}
