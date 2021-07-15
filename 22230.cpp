#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int board[5][5];
	for(int i = 0; i < 5; ++i){
		for(int j = 0; j < 5; ++j){
			cin >> board[i][j];
		}
	}
	for(int i = 0; i < 5; ++i){
		long long sum = 0;
		for(int j = 0; j < 5; ++j){
			sum = sum * 10 + board[i][j];
		}
		if(sum % 171 != 0){
			cout << i << " bad\n";
		}
	}
	for(int j = 0; j < 5; ++j){
		long long sum = 0;
		for(int i = 0; i < 5; ++i){
			sum = sum * 10 + board[i][j];
		}
		if(sum % 171 != 0){
			cout << j << " bad\n";
		}
	}
	long long sum = 0;
	for(int i = 0; i < 5; ++i){
		sum = sum * 10 + board[i][i];
	}
	if(sum % 171 != 0){
		cout << 11 << " bad\n";
	}
	sum = 0;
	for(int i = 0; i < 5; ++i){
		sum = sum * 10 + board[i][4 - i];
	}
	if(sum % 171 != 0){
		cout << 12 << " bad\n";
	}
	for(board[0][0] = 1; board[0][0] <= 9; ++board[0][0]){
		for(board[0][1] = 1; board[0][1] <= 9; ++board[0][1]){
			for(board[0][2] = 1; board[0][2] <= 9; ++board[0][2]){
				for(board[0][3] = 1; board[0][3] <= 9; ++board[0][3]){
					board[0][4] = (1710000 - 10000 * board[0][0] - 1000 * board[0][1] - 100 * board[0][2] - 10 * board[0][3]) % 171;
					if(!(board[0][4] >= 1 && board[0][4] <= 9)){
						continue;
					}
					for(board[1][0] = 1; board[1][0] <= 9; ++board[1][0]){
						for(board[2][0] = 1; board[2][0] <= 9; ++board[2][0]){
							for(board[3][0] = 1; board[3][0] <= 9; ++board[3][0]){
								board[4][0] = (1710000 - 10000 * board[0][0] - 1000 * board[1][0] - 100 * board[2][0] - 10 * board[3][0]) % 171;
								if(!(board[4][0] >= 1 && board[4][0] <= 9)){
									continue;
								}
								for(board[1][3] = 0; board[1][3] <= 9; ++board[1][3]){
									for(board[2][2] = 0; board[2][2] <= 9; ++board[2][2]){
										board[3][1] = (1710000 - 10000 * board[0][4] - 1000 * board[1][3] - 100 * board[2][2] - board[4][0]) * 154 % 171;
										if(board[3][1] > 9){
											continue;
										}
										for(board[1][1] = 0; board[1][1] <= 9; ++board[1][1]){
											for(board[3][3] = 0; board[3][3] <= 9; ++board[3][3]){
												board[4][4] = (1710000 - 10000 * board[0][0] - 1000 * board[1][1] - 100 * board[2][2] - 10 * board[3][3]) % 171;
												if(board[4][4] > 9){
													continue;
												}
												for(board[1][2] = 0; board[1][2] <= 9; ++board[1][2]){
													board[1][4] = (1710000 - 10000 * board[1][0] - 1000 * board[1][1] - 100 * board[1][2] - 10 * board[1][3]) % 171;
													if(board[1][4] > 9){
														continue;
													}
													for(board[2][1] = 0; board[2][1] <= 9; ++board[2][1]){
														board[4][1] = (1710000 - 10000 * board[0][1] - 1000 * board[1][1] - 100 * board[2][1] - 10 * board[3][1]) % 171;
														if(board[4][1] > 9){
															continue;
														}
														for(board[2][3] = 0; board[2][3] <= 9; ++board[2][3]){
															board[2][4] = (1710000 - 10000 * board[2][0] - 1000 * board[2][1] - 100 * board[2][2] - 10 * board[2][3]) % 171;
															if(board[2][4] > 9){
																continue;
															}
															board[4][3] = (1710000 - 10000 * board[0][3] - 1000 * board[1][3] - 100 * board[2][3] - 10 * board[3][3]) % 171;
															if(board[4][3] > 9){
																continue;
															}
															board[4][2] = (1710000 - 10000 * board[4][0] - 1000 * board[4][1] - 10 * board[4][3] - board[4][4]) % 171 * 154 * 154 % 171;
															if(board[4][2] > 9){
																continue;
															}
															board[3][2] = (1710000 - 10000 * board[0][2] - 1000 * board[1][2] - 100 * board[2][2] - board[4][2]) * 154 % 171;
															if(board[3][2] > 9){
																continue;
															}
															board[3][4] = (1710000 - 10000 * board[3][0] - 1000 * board[3][1] - 100 * board[3][2] - 10 * board[3][3]) % 171;
															if(board[3][4] > 9){
																continue;
															}
															if((10000 * board[0][4] + 1000 * board[1][4] + 100 * board[2][4] + 10 * board[3][4] + board[4][4]) % 171 == 0){
																for(int i = 0; i < 5; ++i){
																	for(int j = 0; j < 5; ++j){
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
					}
				}
			}
		}
	}
	return 0;
}
