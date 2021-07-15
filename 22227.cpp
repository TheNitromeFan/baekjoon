#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int board[4][4];
	for(board[0][3] = 2; board[0][3] <= 9; board[0][3] += 2){
		for(board[1][3] = 0; board[1][3] <= 9; board[1][3] += 2){
			for(board[2][3] = 0; board[2][3] <= 9; board[2][3] += 2){
				for(board[3][3] = 0; board[3][3] <= 9; board[3][3] += 2){
					if((1000 * board[0][3] + 100 * board[1][3] + 10 * board[2][3] + board[3][3]) % 31 != 0){
						continue;
					}
					for(board[3][0] = 2; board[3][0] <= 9; board[3][0] += 2){
						for(board[3][1] = 0; board[3][1] <= 9; board[3][1] += 2){
							for(board[3][2] = 0; board[3][2] <= 9; board[3][2] += 2){
								if((1000 * board[3][0] + 100 * board[3][1] + 10 * board[3][2] + board[3][3]) % 31 != 0){
									continue;
								}
								for(board[0][0] = 1; board[0][0] <= 9; ++board[0][0]){
									for(board[0][1] = 1; board[0][1] <= 9; ++board[0][1]){
										board[0][2] = (62000 - 1000 * board[0][0] - 100 * board[0][1] - board[0][3]) * 28 % 31;
										if(!(board[0][2] >= 1 && board[0][2] <= 9)){
											continue;
										}
										for(board[1][1] = 0; board[1][1] <= 9; ++board[1][1]){
											board[2][2] = (62000 - 1000 * board[0][0] - 100 * board[1][1] - board[3][3]) * 28 % 31;
											if(!(board[2][2] >= 0 && board[2][2] <= 9)){
												continue;
											}
											board[2][1] = (62000 - 1000 * board[0][1] - 100 * board[1][1] - board[3][1]) * 28 % 31;
											if(!(board[2][1] >= 0 && board[2][1] <= 9)){
												continue;
											}
											board[1][2] = (62000 - 1000 * board[0][2] - 10 * board[2][2] - board[3][2]) * 28 * 28 % 31;
											if(!(board[1][2] >= 0 && board[1][2] <= 9
											&& (1000 * board[0][3] + 100 * board[1][2] + 10 * board[2][1] + board[3][0]) % 31 == 0)){
												continue;
											}
											board[1][0] = (62000 - 100 * board[1][1] - 10 * board[1][2] - board[1][3]) * 28 * 28 * 28 % 31;
											if(!(board[1][0] >= 1 && board[1][0] <= 9)){
												continue;
											}
											board[2][0] = (62000 - 100 * board[2][1] - 10 * board[2][2] - board[2][3]) * 28 * 28 * 28 % 31;
											if(!(board[2][0] >= 1 && board[2][0] <= 9
											&& (1000 * board[0][0] + 100 * board[1][0] + 10 * board[2][0] + board[3][0]) % 31 == 0)){
												continue;
											}
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
	}
	return 0;
}
