#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int board[5][5];
	for(board[0][4] = 2; board[0][4] <= 9; board[0][4] += 2){
		for(board[1][4] = 0; board[1][4] <= 9; board[1][4] += 2){
			for(board[2][4] = 0; board[2][4] <= 9; board[2][4] += 2){
				for(board[3][4] = 0; board[3][4] <= 9; board[3][4] += 4){
					for(board[4][4] = 0; board[4][4] <= 9; board[4][4] += 4){
						if((board[0][4] + board[1][4] + board[2][4] + board[3][4] + board[4][4]) % 9 != 0){
							continue;
						}
						for(board[4][0] = 2; board[4][0] <= 9; board[4][0] += 2){
							for(board[4][1] = board[4][0] % 4; board[4][1] <= 9; board[4][1] += 4){
								for(board[4][2] = 0; board[4][2] <= 9; board[4][2] += 2){
									for(board[4][3] = 0; board[4][3] <= 9; board[4][3] += 4){
										if((board[4][0] + board[4][1] + board[4][2] + board[4][3] + board[4][4]) % 9 != 0){
											continue;
										}
										for(board[0][3] = (board[0][4] % 4 / 2 + 1) % 2 + 1; board[0][3] <= 9; board[0][3] += 2){
											for(board[1][3] = board[1][4] % 4 / 2; board[1][3] <= 9; board[1][3] += 2){
												for(board[2][3] = board[2][4] % 4 / 2; board[2][3] <= 9; board[2][3] += 2){
													for(board[3][3] = 0; board[3][3] <= 9; board[3][3] += 2){
														if((board[0][3] + board[1][3] + board[2][3] + board[3][3] + board[4][3]) % 9 != 0){
															continue;
														}
														for(board[3][0] = (board[4][0] % 4 / 2 + 1) % 2 + 1; board[3][0] <= 9; board[3][0] += 2){
															for(board[3][1] = board[4][1] % 4 / 2; board[3][1] <= 9; board[3][1] += 2){
																for(board[3][2] = board[4][2] % 4 / 2; board[3][2] <= 9; board[3][2] += 2){
																	if((board[3][0] + board[3][1] + board[3][2] + board[3][3] + board[3][4]) % 9 != 0){
																		continue;
																	}
																	board[2][2] = (81 - board[0][4] - board[1][3] - board[3][1] - board[4][0]) % 9;
																	for(board[0][0] = 1; board[0][0] <= 9; ++board[0][0]){
																		board[1][1] = (81 - board[0][0] - board[2][2] - board[3][3] - board[4][4]) % 9;
																		for(board[0][1] = 1; board[0][1] <= 9; ++board[0][1]){
																			board[2][1] = (81 - board[0][1] - board[1][1] - board[3][1] - board[4][1]) % 9;
																			board[2][0] = (81 - board[2][1] - board[2][2] - board[2][3] - board[2][4]) % 9;
																			if(board[2][0] == 0){
																				continue;
																			}
																			board[1][0] = (81 - board[0][0] - board[2][0] - board[3][0] - board[4][0]) % 9;
																			if(board[1][0] == 0){
																				continue;
																			}
																			board[0][2] = (81 - board[0][0] - board[0][1] - board[0][3] - board[0][4]) % 9;
																			if(board[0][2] == 0){
																				continue;
																			}
																			board[1][2] = (81 - board[1][0] - board[1][1] - board[1][3] - board[1][4]) % 9;
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
			}
		}
	}
	return 0;
}
