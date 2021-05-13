#include <iostream>
#include <unordered_map>
#define MAX 13

using namespace std;

int ways(char map[][MAX], string &s, int dx[8], int dy[8], int n, int m, int x, int y, unsigned pos){
	if(pos == s.length()){
		return 1;
	}
	int ret = 0;
	for(int i = 0; i < 8; ++i){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx < 1){
			nx += n;
		}else if(nx > n){
			nx -= n;
		}
		if(ny < 1){
			ny += m;
		}else if(ny > m){
			ny -= m;
		}
		if(map[nx][ny] == s[pos]){
			ret += ways(map, s, dx, dy, n, m, nx, ny, pos + 1);
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	char map[MAX][MAX];
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			cin >> map[i][j];
		}
	}
	/*
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			cout << map[i][j];
		}
		cout << '\n';
	}
	*/
	int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
	int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
	unordered_map<string, int> memo;
	for(int a0 = 0; a0 < k; ++a0){
		string s;
		cin >> s;
		if(memo.find(s) != memo.end()){
			cout << memo[s] << '\n';
			continue;
		}
		int ans = 0;
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= m; ++j){
				if(map[i][j] == s[0]){
					ans += ways(map, s, dx, dy, n, m, i, j, 1);
				}
			}
		}
		memo[s] = ans;
		cout << ans << '\n';
	}
	return 0;
}
