#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int board[6][6];
	for(board[0][0] = 1; board[0][0] <= 9; ++board[0][0]){
		for(board[0][1] = 1; board[0][1] <= 9; ++board[0][1]){
			for(board[0][2] = 1; board[0][2] <= 9; ++board[0][2]){
				for(board[0][3] = 1; board[0][3] <= 9; ++board[0][3]){
					for(board[0][4] = 1; board[0][4] <= 9; ++board[0][4]){
						board[0][5] = (2590000 - 100000 * board[0][0] - 10000 * board[0][1] - 1000 * board[0][2] - 100 * board[0][3] - 10 * board[0][4]) % 259;
						if(!(board[0][5] >= 1 && board[0][5] <= 9)){
							continue;
						}
						for(board[1][0] = 1; board[1][0] <= 9; ++board[1][0]){
							for(board[2][0] = 1; board[2][0] <= 9; ++board[2][0]){
								for(board[3][0] = 1; board[3][0] <= 9; ++board[3][0]){
									for(board[4][0] = 1; board[4][0] <= 9; ++board[4][0]){
										board[5][0] = (2590000 - 100000 * board[0][0] - 10000 * board[1][0] - 1000 * board[2][0] - 100 * board[3][0] - 10 * board[4][0]) % 259;
										if(!(board[5][0] >= 1 && board[5][0] <= 9)){
											continue;
										}
										for(board[1][1] = 0; board[1][1] <= 9; ++board[1][1]){
											for(board[2][2] = 0; board[2][2] <= 9; ++board[2][2]){
												for(board[3][3] = 0; board[3][3] <= 9; ++board[3][3]){
													for(board[4][4] = 0; board[4][4] <= 9; ++board[4][4]){
														board[5][5] = (2590000 - 100000 * board[0][0] - 10000 * board[1][1] - 1000 * board[2][2] - 100 * board[3][3] - 10 * board[4][4]) % 259;
														if(board[5][5] > 9){
															continue;
														}
														for(board[1][4] = 0; board[1][4] <= 9; ++board[1][4]){
															for(board[2][3] = 0; board[2][3] <= 9; ++board[2][3]){
																for(board[3][2] = 0; board[3][2] <= 9; ++board[3][2]){
																	board[4][1] = (2590000 - 100000 * board[0][5] - 10000 * board[1][4] - 1000 * board[2][3] - 100 * board[3][2] - board[5][0]) % 259 * 26 % 259;
																	if(board[4][1] > 9){
																		continue;
																	}
																	for(board[1][2] = 0; board[1][2] <= 9; ++board[1][2]){
																		for(board[1][3] = 0; board[1][3] <= 9; ++board[1][3]){
																			board[1][5] = (2590000 - 100000 * board[1][0] - 10000 * board[1][1] - 1000 * board[1][2] - 100 * board[1][3] - 10 * board[1][4]) % 259;
																			if(board[1][5] > 9){
																				continue;
																			}
																			for(board[4][2] = 0; board[4][2] <= 9; ++board[4][2]){
																				board[5][2] = (2590000 - 100000 * board[0][2] - 10000 * board[1][2] - 1000 * board[2][2] - 100 * board[3][2] - 10 * board[4][2]) % 259;
																				if(board[5][2] > 9){
																					continue;
																				}
																				for(board[4][3] = 0; board[4][3] <= 9; ++board[4][3]){
																					board[5][3] = (2590000 - 100000 * board[0][3] - 10000 * board[1][3] - 1000 * board[2][3] - 100 * board[3][3] - 10 * board[4][3]) % 259;
																					if(board[5][3] > 9){
																						continue;
																					}
																					board[4][5] = (2590000 - 100000 * board[4][0] - 10000 * board[4][1] - 1000 * board[4][2] - 100 * board[4][3] - 10 * board[4][4]) % 259;
																					if(board[4][5] > 9){
																						continue;
																					}
																					for(board[5][1] = 0; board[5][1] <= 9; ++board[5][1]){
																						board[5][4] = (2590000 - 100000 * board[5][0] - 10000 * board[5][1] - 1000 * board[5][2] - 100 * board[5][3] - board[5][5]) % 259 * 26 % 259;
																						if(board[5][4] > 9){
																							continue;
																						}
																						for(board[2][1] = 0; board[2][1] <= 9; ++board[2][1]){
																							board[3][1] = (2590000 - 100000 * board[0][1] - 10000 * board[1][1] - 1000 * board[2][1] - 10 * board[4][1] - board[5][1]) % 259 * 26 * 26 % 259;
																							if(board[3][1] > 9){
																								continue;
																							}
																							for(board[2][4] = 0; board[2][4] <= 9; ++board[2][4]){
																								board[2][5] = (2590000 - 100000 * board[2][0] - 10000 * board[2][1] - 1000 * board[2][2] - 100 * board[2][3] - 10 * board[2][4]) % 259;
																								if(board[2][5] > 9){
																									continue;
																								}
																								board[3][4] = (2590000 - 100000 * board[0][4] - 10000 * board[1][4] - 1000 * board[2][4] - 10 * board[4][4] - board[5][4]) % 259 * 26 * 26 % 259;
																								if(board[3][4] > 9){
																									continue;
																								}
																								board[3][5] = (2590000 - 100000 * board[3][0] - 10000 * board[3][1] - 1000 * board[3][2] - 100 * board[3][3] - 10 * board[3][4]) % 259;
																								if(board[3][5] > 9){
																									continue;
																								}
																								if((100000 * board[0][5] + 10000 * board[1][5] + 1000 * board[2][5] + 100 * board[3][5] + 10 * board[4][5] + board[5][5]) % 259 == 0){
																									for(int i = 0; i < 6; ++i){
																										for(int j = 0; j < 6; ++j){
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
						}
					}
				}
			}
		}
	}
	return 0;
}
