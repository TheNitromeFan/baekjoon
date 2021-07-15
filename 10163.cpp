#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int board[1002][1002] = {};
	int n;
	cin >> n;
	for(int paper = 1; paper <= n; ++paper){
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		for(int i = x; i < x + a; ++i){
			for(int j = y; j < y + b; ++j){
				board[i][j] = paper;
			}
		}
	}
	int cnt[101] = {};
	for(int i = 0; i < 1002; ++i){
		for(int j = 0; j < 1002; ++j){
			++cnt[board[i][j]];
		}
	}
	for(int c = 1; c <= n; ++c){
		cout << cnt[c] << '\n';
	}
	return 0;
}
