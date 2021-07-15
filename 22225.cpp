#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	srand((unsigned)time(NULL));
	int board[10][10];
	for(int i = 0; i < 10; ++i){
		for(int j = 0; j < 10; ++j){
			cin >> board[i][j];
		}
	}
	for(int i = 0; i < 10; ++i){
		long long sum = 0;
		for(int j = 0; j < 10; ++j){
			sum = sum * 10 + board[i][j];
		}
		if(sum % 45 != 0){
			cout << i << " bad\n";
		}
	}
	for(int j = 0; j < 10; ++j){
		long long sum = 0;
		for(int i = 0; i < 10; ++i){
			sum = sum * 10 + board[i][j];
		}
		if(sum % 45 != 0){
			cout << j << " bad\n";
		}
	}
	long long sum = 0;
	for(int i = 0; i < 10; ++i){
		sum = sum * 10 + board[i][i];
	}
	if(sum % 45 != 0){
		cout << 11 << " bad\n";
	}
	sum = 0;
	for(int i = 0; i < 10; ++i){
		sum = sum * 10 + board[i][9 - i];
	}
	if(sum % 45 != 0){
		cout << 12 << " bad\n";
	}
	memset(board, -1, sizeof(board));
	for(int i = 0; i < 10; ++i){
		if(i != 3){
			board[i][9] = 5;
		}else{
			board[i][9] = 0;
		}
		if(i != 6){
			board[9][i] = 5;
		}else{
			board[9][i] = 0;
		}
	}
	int row1 = board[0][9];
	for(int i = 0; i < 8; ++i){
		board[0][i] = rand() % 9 + 1;
		row1 += board[0][i];
	}
	board[0][8] = (9000 - 1 - row1) % 9 + 1;
	int col1 = board[0][0] + 5;
	for(int i = 1; i < 8; ++i){
		board[i][0] = rand() % 9 + 1;
		col1 += board[i][0];
	}
	board[8][0] = (9000 - 1 - col1) % 9 + 1;
	int diag1 = 5 + board[0][0];
	for(int i = 1; i < 8; ++i){
		board[i][i] = rand() % 10;
		diag1 += board[i][i];
	}
	board[8][8] = (9000 - diag1) % 9;
	int diag2 = 10;
	for(int i = 1; i < 8; ++i){
		board[i][9 - i] = rand() % 10;
		diag2 += board[i][9 - i];
	}
	board[8][1] = (9000 - diag2) % 9;
	int row2 = board[1][0] + board[1][1] + board[1][8] + board[1][9];
	for(int j = 2; j < 7; ++j){
		board[1][j] = rand() % 10;
		row2 += board[1][j];
	}
	board[1][7] = (9000 - row2) % 9;
	int row9 = board[8][0] + board[8][1] + board[8][8] + board[8][9];
	for(int j = 2; j < 7; ++j){
		board[8][j] = rand() % 10;
		row9 += board[8][j];
	}
	board[8][7] = (9000 - row9) % 9;
	for(int i = 2; i < 6; ++i){
		int sum = 0;
		for(int j = 0; j < 10; ++j){
			if(j == 8){
				continue;
			}
			if(board[i][j] == -1){
				board[i][j] = rand() % 10;
			}
			sum += board[i][j];
		}
		board[i][8] = (9000 - sum) % 9;
	}
	for(int j = 2; j < 10; j += 5){
		int sum = 0;
		for(int i = 0; i < 10; ++i){
			if(i != 6){
				sum += board[i][j];
			}
		}
		board[6][j] = (9000 - sum) % 9;
	}
	for(int j = 3; j < 9; j += 3){
		int sum = 0;
		for(int i = 0; i < 10; ++i){
			if(i != 7){
				sum += board[i][j];
			}
		}
		board[7][j] = (9000 - sum) % 9;
	}
	board[6][1] = rand() % 10;
	board[6][4] = rand() % 10;
	board[6][5] = rand() % 10;
	sum = 0;
	for(int j = 0; j < 10; ++j){
		if(j != 8){
			sum += board[6][j];
		}
	}
	board[6][8] = (9000 - sum) % 9;
	sum = 0;
	for(int i = 0; i < 10; ++i){
		if(i != 7){
			sum += board[i][1];
		}
	}
	board[7][1] = (9000 - sum) % 9;
	sum = 0;
	for(int i = 0; i < 10; ++i){
		if(i != 7){
			sum += board[i][4];
		}
	}
	board[7][4] = (9000 - sum) % 9;
	sum = 0;
	for(int i = 0; i < 10; ++i){
		if(i != 7){
			sum += board[i][5];
		}
	}
	board[7][5] = (9000 - sum) % 9;
	sum = 0;
	for(int i = 0; i < 10; ++i){
		if(i != 7){
			sum += board[i][8];
		}
	}
	board[7][8] = (9000 - sum) % 9;
	for(int i = 0; i < 10; ++i){
		for(int j = 0; j < 10; ++j){
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	return 0;
}
