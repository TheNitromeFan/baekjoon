#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int board[3][3];
	for(board[0][0] = 1; board[0][0] <= 9; ++board[0][0]){
		for(board[0][1] = 1; board[0][1] <= 9; ++board[0][1]){
			board[0][2] = (2600 - 100 * board[0][0] - 10 * board[0][1]) % 13;
			if(!(board[0][2] >= 1 && board[0][2] <= 9)){
				continue;
			}
			for(board[1][1] = 0; board[1][1] <= 9; ++board[1][1]){
				board[2][0] = (2600 - 100 * board[0][2] - 10 * board[1][1]) % 13;
				if(!(board[2][0] >= 1 && board[2][0] <= 9)){
					continue;
				}
				board[1][0] = (2600 - 100 * board[0][0] - board[2][0]) * 4 % 13;
				if(!(board[1][0] >= 1 && board[1][0] <= 9)){
					continue;
				}
				board[1][2] = (2600 - 100 * board[1][0] - 10 * board[1][1]) % 13;
				if(!(board[1][2] >= 0 && board[1][2] <= 9)){
					continue;
				}
				board[2][1] = (2600 - 100 * board[0][1] - 10 * board[1][1]) % 13;
				if(!(board[2][1] >= 0 && board[2][1] <= 9)){
					continue;
				}
				board[2][2] = (2600 - 100 * board[2][0] - 10 * board[2][1]) % 13;
				if(!(board[2][2] >= 0 && board[2][2] <= 9
				&& (100 * board[0][0] + 10 * board[1][1] + board[2][2]) % 13 == 0
				&& (100 * board[0][2] + 10 * board[1][2] + board[2][2]) % 13 == 0)){
					continue;
				}
				for(int i = 0; i < 3; ++i){
					for(int j = 0; j < 3; ++j){
						cout << board[i][j] << ' ';
					}
					cout << '\n';
				}
				cout << '\n';
			}
		}
	}
	return 0;
}
