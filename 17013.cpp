#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	int board[4] = {1, 2, 3, 4};
	string flips;
	cin >> flips;
	int h = 0, v = 0;
	for(char c : flips){
		if(c == 'H'){
			++h;
		}else{
			++v;
		}
	}
	if(h % 2 == 1){
		swap(board[0], board[2]);
		swap(board[1], board[3]);
	}
	if(v % 2 == 1){
		swap(board[0], board[1]);
		swap(board[2], board[3]);
	}
	cout << board[0] << ' ' << board[1] << '\n' << board[2] << ' ' << board[3];
	return 0;
}
