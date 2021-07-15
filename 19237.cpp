#include <iostream>
#include <queue>
#define MAXN 21
#define MAXM 1001

using namespace std;

int simulate(int map[][MAXN], int x[MAXM], int y[MAXM], int d[MAXM], int dir_select[][5][5], int n, int m, int k){
	int dx[5] = {0, -1, 1, 0, 0};
	int dy[5] = {0, 0, 0, -1, 1};
	bool eaten[MAXM] = {};
	int alive = m;
	int nx[MAXM], ny[MAXM];
	int last[MAXM][MAXN][MAXN] = {};
	queue<int> q[MAXM];
	for(int shark = 1; shark <= m; ++shark){
		q[shark].push(x[shark]);
		q[shark].push(y[shark]);
	}
	for(int turn = 1; turn <= 1000; ++turn){
		for(int shark = 1; shark <= m; ++shark){
			if(eaten[shark]){
				continue;
			}
			int xpos = x[shark], ypos = y[shark], dir = d[shark];
			int nxpos = -1, nypos = -1, ndir = -1;
			for(int i = 1; i <= 4; ++i){
				nxpos = xpos + dx[dir_select[shark][dir][i]];
				nypos = ypos + dy[dir_select[shark][dir][i]];
				if(nxpos >= 1 && nxpos <= n && nypos >= 1 && nypos <= n && map[nxpos][nypos] == 0){
					ndir = dir_select[shark][dir][i];
					break;
				}
			}
			if(ndir == -1){
				for(int i = 1; i <= 4; ++i){
					nxpos = xpos + dx[dir_select[shark][dir][i]];
					nypos = ypos + dy[dir_select[shark][dir][i]];
					if(nxpos >= 1 && nxpos <= n && nypos >= 1 && nypos <= n && map[nxpos][nypos] == shark){
						ndir = dir_select[shark][dir][i];
						break;
					}
				}
			}
			nx[shark] = nxpos;
			ny[shark] = nypos;
			d[shark] = ndir;
		}
		for(int shark = m; shark >= 1; --shark){
			if(eaten[shark]){
				continue;
			}
			int xpos = nx[shark], ypos = ny[shark];
			if(map[xpos][ypos] != 0 && map[xpos][ypos] != shark && !eaten[map[xpos][ypos]]){
				eaten[map[xpos][ypos]] = true;
				--alive;
				if(alive == 1){
					return turn;
				}
			}
			map[xpos][ypos] = shark;
			x[shark] = xpos;
			y[shark] = ypos;
			q[shark].push(xpos);
			q[shark].push(ypos);
			last[shark][xpos][ypos] = turn;
		}
		if(turn >= k){
			for(int shark = 1; shark <= m; ++shark){
				if(q[shark].empty()){
					continue;
				}
				int xpos = q[shark].front();
				q[shark].pop();
				int ypos = q[shark].front();
				q[shark].pop();
				if(map[xpos][ypos] == shark && last[shark][xpos][ypos] == turn - k){
					// cout << shark << ' ' << xpos << ' ' << ypos << ' ' << turn << '\n';
					map[xpos][ypos] = 0;
					last[shark][xpos][ypos] = 0;
				}
			}
		}
		/*
		cout << "Sharks:\n";
		for(int shark = 1; shark <= n; ++shark){
			cout << shark << ": " << x[shark] << ' ' << y[shark] << ' ' << d[shark] << '\n';
		}
		cout << '\n';
		cout << "Map:\n";
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				cout << map[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
		cout << "Last:\n";
		for(int shark = 1; shark <= m; ++shark){
			cout << shark << '\n' << '\n';
			for(int i = 1; i <= n; ++i){
				for(int j = 1; j <= n; ++j){
					cout << last[shark][i][j] << ' ';
				}
				cout << '\n';
			}
			cout << '\n';
		}
		cout << '\n';
		*/
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	int map[MAXN][MAXN];
	int x[MAXM], y[MAXM], dir[MAXM];
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			cin >> map[i][j];
			if(map[i][j] != 0){
				x[map[i][j]] = i;
				y[map[i][j]] = j;
			}
		}
	}
	for(int shark = 1; shark <= m; ++shark){
		cin >> dir[shark];
	}
	int dir_select[MAXM][5][5];
	for(int shark = 1; shark <= m; ++shark){
		for(int i = 1; i <= 4; ++i){
			for(int j = 1; j <= 4; ++j){
				cin >> dir_select[shark][i][j];
			}
		}
	}
	cout << simulate(map, x, y, dir, dir_select, n, m, k) << '\n';
	return 0;
}
