#include <iostream>
#include <cstring>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int board[7][7];
	memset(board, -1, sizeof(board));
	board[3][3] = 1;
	board[3][4] = 0;
	board[4][3] = 0;
	board[4][4] = 1;
	int n;
	cin >> n;
	int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
	int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
	for(int a0 = 0; a0 < n; ++a0){
		int r, c;
		cin >> r >> c;
		int color = a0 % 2;
		for(int i = 0; i < 8; ++i){
			int nr = r, nc = c;
			while(true){
				nr += dx[i];
				nc += dy[i];
				if(nr >= 1 && nr <= 6 && nc >= 1 && nc <= 6 && board[nr][nc] == color){
					for(int nnr = r, nnc = c; !(nnr == nr && nnc == nc); nnr += dx[i], nnc += dy[i]){
						board[nnr][nnc] = color;
					}
					break;
				}else if(!(nr >= 1 && nr <= 6 && nc >= 1 && nc <= 6 && board[nr][nc] == 1 - color)){
					break;
				}
			}
		}
	}
	int black = 0, white = 0;
	for(int r = 1; r <= 6; ++r){
		for(int c = 1; c <= 6; ++c){
			if(board[r][c] == 0){
				++black;
				cout << 'B';
			}else if(board[r][c] == 1){
				++white;
				cout << 'W';
			}else{
				cout << '.';
			}
		}
		cout << '\n';
	}
	cout << (black > white ? "Black" : "White") << '\n';
	return 0;
}
