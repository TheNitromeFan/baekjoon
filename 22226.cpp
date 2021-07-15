#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int board[4][4];
	for(board[0][0] = 1; board[0][0] <= 9; ++board[0][0]){
		for(board[0][1] = 1; board[0][1] <= 9; ++board[0][1]){
			for(board[0][2] = 1; board[0][2] <= 9; ++board[0][2]){
				board[0][3] = (51000 - 1000 * board[0][0] - 100 * board[0][1] - 10 * board[0][2]) % 51;
				if(!(board[0][3] >= 1 && board[0][3] <= 9)){
					continue;
				}
				for(board[1][0] = 1; board[1][0] <= 9; ++board[1][0]){
					for(board[2][0] = 1; board[2][0] <= 9; ++board[2][0]){
						board[3][0] = (51000 - 1000 * board[0][0] - 100 * board[1][0] - 10 * board[2][0]) % 51;
						if(!(board[3][0] >= 1 && board[3][0] <= 9)){
							continue;
						}
						for(board[1][1] = 0; board[1][1] <= 9; ++board[1][1]){
							for(board[1][2] = 0; board[1][2] <= 9; ++board[1][2]){
								board[1][3] = (51000 - 1000 * board[1][0] - 100 * board[1][1] - 10 * board[1][2]) % 51;
								if(!(board[1][3] >= 0 && board[1][3] <= 9)){
									continue;
								}
								board[2][1] = (51000 - 1000 * board[0][3] - 100 * board[1][2] - board[3][0]) * 46 % 51;
								if(!(board[2][1] >= 0 && board[2][1] <= 9)){
									continue;
								}
								board[3][1] = (51000 - 1000 * board[0][1] - 100 * board[1][1] - 10 * board[2][1]) % 51;
								if(!(board[3][1] >= 0 && board[3][1] <= 9)){
									continue;
								}
								for(board[2][2] = 0; board[2][2] <= 9; ++board[2][2]){
									board[2][3] = (51000 - 1000 * board[2][0] - 100 * board[2][1] - 10 * board[2][2]) % 51;
									if(!(board[2][3] >= 0 && board[2][3] <= 9)){
										continue;
									}
									board[3][2] = (51000 - 1000 * board[0][2] - 100 * board[1][2] - 10 * board[2][2]) % 51;
									if(!(board[3][2] >= 0 && board[3][2] <= 9)){
										continue;
									}
									board[3][3] = (51000 - 1000 * board[0][0] - 100 * board[1][1] - 10 * board[2][2]) % 51;
									if(!(board[3][3] >= 0 && board[3][3] <= 9)){
										continue;
									}
									if((1000 * board[0][3] + 100 * board[1][3] + 10 * board[2][3] + board[3][3]) % 51 == 0
									&& (1000 * board[3][0] + 100 * board[3][1] + 10 * board[3][2] + board[3][3]) % 51 == 0){
										for(int i = 0; i < 4; ++i){
											for(int j = 0; j < 4; ++j){
												cout << board[i][j] << ' ';
											}
											cout << '\n';
										}
										cout << '\n';
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
