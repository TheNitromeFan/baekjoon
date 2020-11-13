#include <iostream>
#include <string>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 1; a0 <= t; ++a0){
		int board[65][65] = {};
		int x, y;
		cin >> x >> y;
		int n = 0;
		int dir = 0;
		board[x][y] = 1;
		string move;
		cin >> move;
		for(char c : move){
			if(c == 'F'){
				x += dx[dir];
				y += dy[dir];
				if(board[x][y] == 1){
					++n;
				}
				++board[x][y];
			}else if(c == 'R'){
				dir = (dir + 1) % 4;
			}else if(c == 'L'){
				dir = (dir + 3) % 4;
			}
		}
		cout << "Case #" << a0 << ": " << x << " " << y << " " << n << "\n";
	}
	return 0;
}
