#include <iostream>
#include <string>
#include <iomanip>
#define MAX 513

using namespace std;

void fill_board(char board[][MAX], string &quad, int n, int x, int y, int &pos){
	if(quad[pos] == 'Q'){
		++pos;
		fill_board(board, quad, n / 2, x, y, pos);
		fill_board(board, quad, n / 2, x, y + n / 2, pos);
		fill_board(board, quad, n / 2, x + n / 2, y, pos);
		fill_board(board, quad, n / 2, x + n / 2, y + n / 2, pos);
		return;
	}
	for(int i = x; i < x + n; ++i){
		for(int j = y; j < y + n; ++j){
			board[i][j] = quad[pos];
		}
	}
	++pos;
}

void print_hex(char board[][MAX], int i, int j){
	int val = 0;
	for(int k = 0, col = j; col < j + 8; ++k, ++col){
		val += (board[i][col] == 'B') * (1 << k);
	}
	cout << "0x" << setfill('0') << hex << setw(2) << val << ",";
}

void xbm(char board[][MAX], int n){
	cout << "#define quadtree_width " << n << "\n";
	cout << "#define quadtree_height " << n << "\n";
	cout << "static char quadtree_bits[] = {\n";
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; j += 8){
			print_hex(board, i, j);
		}
		cout << "\n";
	}
	cout << "};";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string quad;
	cin >> quad;
	char board[MAX][MAX];
	int pos = 0;
	fill_board(board, quad, n, 0, 0, pos);
	/*
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cout << board[i][j];
		}
		cout << '\n';
	}
	*/
	xbm(board, n);
	return 0;
}
