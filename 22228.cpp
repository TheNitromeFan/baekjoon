#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int board[6][6] =
	{
		{2, 3, 7, 6, 2, 5},
		{4, 6, 2, 0, 0, 0},
		{8, 3, 3, 0, 0, 0},
		{3, 6, 1, 0, 0, 0},
		{7, 2, 2, 0, 0, 0},
		{5, 5, 5, 0, 0, 0}
	};
	for(int i = 0; i < 6; ++i){
		for(int j = 0; j < 6; ++j){
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
