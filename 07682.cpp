#include <iostream>
#include <string>

using namespace std;

int count(char board[][4], char c){
	int ret = 0;
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			if(board[i][j] == c){
				++ret;
			}
		}
	}
	return ret;
}

bool wins(char board[][4], char c){
	for(int i = 0; i < 3; ++i){
		if(board[i][0] == c && board[i][1] == c && board[i][2] == c){
			return true;
		}
	}
	for(int j = 0; j < 3; ++j){
		if(board[0][j] == c && board[1][j] == c && board[2][j] == c){
			return true;
		}
	}
	if(board[0][0] == c && board[1][1] == c && board[2][2] == c){
		return true;
	}
	if(board[0][2] == c && board[1][1] == c && board[2][0] == c){
		return true;
	}
	return false;
}

bool valid(char board[][4]){
	int xcnt = count(board, 'X'), ocnt = count(board, 'O');
	bool xwins = wins(board, 'X'), owins = wins(board, 'O');
	if(!(xcnt == ocnt || xcnt == ocnt + 1) || (xwins && owins)){
		return false;
	}
	if(xwins){
		return xcnt == ocnt + 1;
	}else if(owins){
		return xcnt == ocnt;
	}else{
		return xcnt == 5 && ocnt == 4;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string line;
	while(true){
		cin >> line;
		if(line == "end"){
			break;
		}
		char board[3][4];
		for(int i = 0; i < 3; ++i){
			for(int j = 0; j < 3; ++j){
				board[i][j] = line[i * 3 + j];
			}
		}
		cout << (valid(board) ? "valid" : "invalid") << '\n';
	}
	return 0;
}
