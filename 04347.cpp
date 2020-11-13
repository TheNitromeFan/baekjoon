#include <iostream>
#include <string>

using namespace std;

int cnt(char board[][4], char player){
	int ret = 0;
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			if(board[i][j] == player){
				++ret;
			}
		}
	}
	return ret;
}

bool wins(char board[][4], char player){
	for(int i = 0; i < 3; ++i){
		if(board[i][0] == player && board[i][1] == player && board[i][2] == player){
			return true;
		}
	}
	for(int j = 0; j < 3; ++j){
		if(board[0][j] == player && board[1][j] == player && board[2][j] == player){
			return true;
		}
	}
	if(board[0][0] == player && board[1][1] == player && board[2][2] == player){
		return true;
	}
	if(board[0][2] == player && board[1][1] == player && board[2][0] == player){
		return true;
	}
	return false;
}

bool valid(char board[][4]){
	bool xwins = wins(board, 'X'), owins = wins(board, 'O');
	int xcnt = cnt(board, 'X'), ocnt = cnt(board, 'O');
	// cout << xwins << ' ' << owins << ' ' << xcnt << ' ' << ocnt << '\n';
	return !(xcnt < ocnt || ocnt + 1 < xcnt || (xwins && owins) || (xwins && xcnt == ocnt) || (owins && xcnt != ocnt));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int a0 = 0; a0 < n; ++a0){
		string line;
		getline(cin, line);
		char board[4][4];
		for(int i = 0; i < 3; ++i){
			getline(cin, line);
			for(int j = 0; j < 3; ++j){
				board[i][j] = line[j];
			}
		}
		cout << (valid(board) ? "yes" : "no") << '\n';
	}
	return 0;
}
