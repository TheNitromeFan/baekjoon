#include <iostream>
#include <string>

using namespace std;

string binary(char mat[][21], int r, int c){
	string ret = "";
	int x = 0, y = 0;
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	int dir = 0;
	bool visited[21][21] = {};
	while(true){
		ret += mat[x][y];
		visited[x][y] = true;
		int nx = x + dx[dir], ny = y + dy[dir];
		int turns = 0;
		while(!(nx >= 0 && nx < r && ny >= 0 && ny < c && !visited[nx][ny])){
			++turns;
			dir = (dir + 1) % 4;
			nx = x + dx[dir];
			ny = y + dy[dir];
			if(turns == 4){
				return ret;
			}
		}
		x = nx;
		y = ny;
	}
	return "";
}

char letter(string &s, unsigned pos){
	int val = 0;
	for(unsigned i = 0; i < 5; ++i){
		val *= 2;
		val += s[pos + i] - '0';
	}
	if(val == 0){
		return ' ';
	}
	return 'A' + val - 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		int r, c;
		string s;
		cin >> r >> c >> s;
		char mat[21][21];
		for(int j = 0; j < r; ++j){
			for(int k = 0; k < c; ++k){
				mat[j][k] = s[j * c + k];
			}
		}
		string decoded = binary(mat, r, c);
		// cout << decoded << '\n';
		string ans = "", tmp = "";
		for(unsigned i = 0; i + 5 <= decoded.length(); i += 5){
			char c = letter(decoded, i);
			tmp += letter(decoded, i);
			if(c != ' '){
				ans = tmp;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
