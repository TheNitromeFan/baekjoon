#include <cstdio>

int can_place_evens[10][10], can_place_odds[10][10];

bool board_evens[10][10], board_odds[10][10];

bool is_safe_evens(int size, int row, int column){
	for(int i = row, j = column; i >= 0 && j >= 0; --i, --j){
		if(board_evens[i][j]){
			return false;
		}
	}
	return true;
}

bool is_safe_odds(int size, int row, int column){
	for(int i = row, j = column; i >= 0 && j >= 0; --i, --j){
		if(board_odds[i][j]){
			return false;
		}
	}
	return true;
}

int solve_evens(int size, int top_left_diag){
	if(top_left_diag >= 2 * size){
		int cnt = 0;
		for(int i = 0; i < size; ++i){
			for(int j = 0; j < size; ++j){
				if(board_evens[i][j]){
					++cnt;
				}
			}
		}
		return cnt;
	}
	int ans = solve_evens(size, top_left_diag + 1), cmp;
	if(top_left_diag <= size){
		for(int i = 0; i < top_left_diag; ++i){
			int j = top_left_diag - 1 - i;
			if(can_place_evens[i][j] && is_safe_evens(size, i, j)){
				board_evens[i][j] = true;
				cmp = solve_evens(size, top_left_diag + 1);
				if(cmp > ans){
					ans = cmp;
				}
				board_evens[i][j] = false;
			}
		}
	}else{
		for(int i = top_left_diag - size; i < size; ++i){
			int j = top_left_diag - 1 - i;
			if(is_safe_evens(size, i, j)){
				board_evens[i][j] = true;
				int cmp = solve_evens(size, top_left_diag + 1);
				if(cmp > ans){
					ans = cmp;
				}
				board_evens[i][j] = false;
			}
		}
	}
	return ans;
}

int solve_odds(int size, int top_left_diag){
	if(top_left_diag >= 2 * size){
		int cnt = 0;
		for(int i = 0; i < size; ++i){
			for(int j = 0; j < size; ++j){
				printf("%d ", board_odds[i][j]); 
				if(board_odds[i][j]){
					++cnt;
				}
			}
			printf("\n");
		}
		printf("%d\n", cnt);
		return cnt;
	}
	int ans = solve_odds(size, top_left_diag + 1), cmp;
	if(top_left_diag <= size){
		for(int i = 0; i < top_left_diag; ++i){
			int j = top_left_diag - 1 - i;
			if(can_place_odds[i][j] && is_safe_odds(size, i, j)){
				printf("can place: %d %d\n", i, j);
				board_odds[i][j] = true;
				cmp = solve_odds(size, top_left_diag + 1);
				if(cmp > ans){
					ans = cmp;
				}
				board_odds[i][j] = false;
			}
		}
	}else{
		for(int i = top_left_diag - size; i < size; ++i){
			int j = top_left_diag - 1 - i;
			if(is_safe_odds(size, i, j)){
				board_odds[i][j] = true;
				int cmp = solve_odds(size, top_left_diag + 1);
				if(cmp > ans){
					ans = cmp;
				}
				board_odds[i][j] = false;
			}
		}
	}
	return ans;
}

int main(void){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if((i + j) % 2 == 0){
				scanf("%d", &can_place_evens[i][j]);
			}else{
				scanf("%d", &can_place_odds[i][j]);
			}
		}
	}
	/*
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			printf("%d ", can_place_evens[i][j]);
		}
		printf("\n");
	}
	*/
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			printf("%d ", can_place_odds[i][j]);
		}
		printf("\n");
	}
	printf("%d %d", solve_evens(n, 1), solve_odds(n, 1));
	return 0;
}
