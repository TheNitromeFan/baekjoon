#include <iostream>
#include <queue>
#define MAX 21
#define MAXCNT 11

using namespace std;

int threshold[MAXCNT];

int max_value(int board[][MAX], int n){
	int ret = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(ret < board[i][j]){
				ret = board[i][j];
			}
		}
	}
	return ret;
}

void copy_array(int a[][MAX], int b[][MAX], int n){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			b[i][j] = a[i][j];
		}
	}
}

bool array_equal(int a[][MAX], int b[][MAX], int n){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(a[i][j] != b[i][j]){
				return false;
			}
		}
	}
	return true;
}

void push(int board[][MAX], int n, int dir){
	queue<int> q;
	if(dir == 0){
		for(int j = 0; j < n; ++j){
			for(int i = 0; i < n; ++i){
				if(board[i][j] != 0){
					q.push(board[i][j]);
					board[i][j] = 0;
				}
			}
			int idx = 0;
			while(!q.empty()){
				if(board[idx][j] == 0){
					board[idx][j] = q.front();
				}else if(board[idx][j] == q.front()){
					board[idx][j] += q.front();
					++idx;
				}else{
					++idx;
					board[idx][j] = q.front();
				}
				q.pop();
			}
		}
	}else if(dir == 1){
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				if(board[i][j] != 0){
					q.push(board[i][j]);
					board[i][j] = 0;
				}
			}
			int idx = 0;
			while(!q.empty()){
				if(board[i][idx] == 0){
					board[i][idx] = q.front();
				}else if(board[i][idx] == q.front()){
					board[i][idx] += q.front();
					++idx;
				}else{
					++idx;
					board[i][idx] = q.front();
				}
				q.pop();
			}
		}
	}else if(dir == 2){
		for(int j = 0; j < n; ++j){
			for(int i = n - 1; i >= 0; --i){
				if(board[i][j] != 0){
					q.push(board[i][j]);
					board[i][j] = 0;
				}
			}
			int idx = n - 1;
			while(!q.empty()){
				if(board[idx][j] == 0){
					board[idx][j] = q.front();
				}else if(board[idx][j] == q.front()){
					board[idx][j] += q.front();
					--idx;
				}else{
					--idx;
					board[idx][j] = q.front();
				}
				q.pop();
			}
		}
	}else if(dir == 3){
		for(int i = 0; i < n; ++i){
			for(int j = n - 1; j >= 0; --j){
				if(board[i][j] != 0){
					q.push(board[i][j]);
					board[i][j] = 0;
				}
			}
			int idx = n - 1;
			while(!q.empty()){
				if(board[i][idx] == 0){
					board[i][idx] = q.front();
				}else if(board[i][idx] == q.front()){
					board[i][idx] += q.front();
					--idx;
				}else{
					--idx;
					board[i][idx] = q.front();
				}
				q.pop();
			}
		}
	}
}

void dfs(int board[][MAX], int n, int cnt, int &ans){
	int val = max_value(board, n);
	if(val <= threshold[cnt]){
		return;
	}
	if(cnt == 5){
		if(val > ans){
			ans = val;
		}
		int v = ans;
		while(cnt > 0){
			threshold[cnt] = v;
			--cnt;
			v /= 2;
		}
		return;
	}
	int tmp[MAX][MAX] = {};
	copy_array(board, tmp, n);
	for(int dir = 0; dir < 4; ++dir){
		push(board, n, dir);
		/*
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				cout << board[i][j] << ' ';
			}
			cout << '\n';
		}
		*/
		if(!array_equal(tmp, board, n)){
			dfs(board, n, cnt + 1, ans);
			copy_array(tmp, board, n);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int board[MAX][MAX] = {};
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> board[i][j];
		}
	}
	int ans = max_value(board, n);
	dfs(board, n, 0, ans);
	cout << ans;
	return 0;
}
