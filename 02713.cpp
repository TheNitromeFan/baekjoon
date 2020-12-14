#include <iostream>
#include <string>
#define MAX 21

using namespace std;

string binary(char c){
	if(c == ' '){
		return "00000";
	}
	int x = c - 'A' + 1;
	string ret;
	for(int i = 0; i < 5; ++i){
		if(x % 2 == 1){
			ret = "1" + ret;
		}else{
			ret = "0" + ret;
		}
		x /= 2;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int a0 = 0; a0 < n; ++a0){
		int r, c;
		string s;
		cin >> r >> c;
		getline(cin, s);
		s.erase(s.begin());
		string spiral;
		for(char x : s){
			spiral += binary(x);
		}
		spiral.resize(r * c, '0');
		int dx[4] = {0, 1, 0, -1};
		int dy[4] = {1, 0, -1, 0};
		char map[MAX][MAX] = {};
		int x = 0, y = 0, dir = 0;
		for(int i = 0; i < r * c; ++i){
			map[x][y] = spiral[i];
			int nx = x + dx[dir], ny = y + dy[dir];
			if(!(nx >= 0 && nx < r && ny >= 0 && ny < c && map[nx][ny] == 0)){
				dir = (dir + 1) % 4;
				nx = x + dx[dir];
				ny = y + dy[dir];
			}
			x = nx;
			y = ny;
		}
		for(int i = 0; i < r; ++i){
			for(int j = 0; j < c; ++j){
				cout << map[i][j];
			}
		}
		cout << '\n';
	}
	return 0;
}
