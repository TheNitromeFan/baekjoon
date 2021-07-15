#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int score;
	cin >> score;
	string seq;
	cin >> seq;
	int board[4][4] = {};
	for(int i = 0; i < 4; ++i){
		for(int j = 0; j < 4; ++j){
			cin >> board[i][j];
		}
	}
	for(unsigned idx = 0; idx < seq.length(); idx += 4){
		char move = seq[idx];
		int tile = seq[idx + 1] - '0';
		int at_row = seq[idx + 2] - '0';
		int at_col = seq[idx + 3] - '0';
		if(move == 'L'){
			for(int i = 0; i < 4; ++i){
				queue<int> q;
				for(int j = 0; j < 4; ++j){
					if(board[i][j] != 0){
						q.push(board[i][j]);
						board[i][j] = 0;
					}
				}
				int col = 0;
				while(!q.empty()){
					int x = q.front();
					q.pop();
					if(!q.empty() && q.front() == x){
						x += q.front();
						q.pop();
						score += x;
					}
					board[i][col] = x;
					++col;
				}
			}
		}else if(move == 'R'){
			for(int i = 0; i < 4; ++i){
				queue<int> q;
				for(int j = 3; j >= 0; --j){
					if(board[i][j] != 0){
						q.push(board[i][j]);
						board[i][j] = 0;
					}
				}
				int col = 3;
				while(!q.empty()){
					int x = q.front();
					q.pop();
					if(!q.empty() && q.front() == x){
						x += q.front();
						q.pop();
						score += x;
					}
					board[i][col] = x;
					--col;
				}
			}
		}else if(move == 'U'){
			for(int j = 0; j < 4; ++j){
				queue<int> q;
				for(int i = 0; i < 4; ++i){
					if(board[i][j] != 0){
						q.push(board[i][j]);
						board[i][j] = 0;
					}
				}
				int row = 0;
				while(!q.empty()){
					int x = q.front();
					q.pop();
					if(!q.empty() && q.front() == x){
						x += q.front();
						q.pop();
						score += x;
					}
					board[row][j] = x;
					++row;
				}
			}
		}else{
			for(int j = 0; j < 4; ++j){
				queue<int> q;
				for(int i = 3; i >= 0; --i){
					if(board[i][j] != 0){
						q.push(board[i][j]);
						board[i][j] = 0;
					}
				}
				int row = 3;
				while(!q.empty()){
					int x = q.front();
					q.pop();
					if(!q.empty() && q.front() == x){
						x += q.front();
						q.pop();
						score += x;
					}
					board[row][j] = x;
					--row;
				}
			}
		}
		board[at_row][at_col] = tile;
	}
	cout << score << '\n';
	return 0;
}
