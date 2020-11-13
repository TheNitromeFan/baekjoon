#include <iostream>
#include <string>
#include <algorithm>
#define MAX 10

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct person{
	string name;
	int posx;
	int posy;
	int dir;
} players[MAX];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for(int c = 1; c <= t; ++c){
		int m, n, p;
		cin >> m >> n >> p;
		int map[MAX][MAX] = {};
		for(int i = 0; i < p; ++i){
			char d;
			cin >> players[i].name >> players[i].posx >> players[i].posy >> d;
			if(d == 'E'){
				players[i].dir = 0;
			}else if(d == 'N'){
				players[i].dir = 1;
			}else if(d == 'W'){
				players[i].dir = 2;
			}else if(d == 'S'){
				players[i].dir = 3;
			}
			map[players[i].posx][players[i].posy] += 1;
		}
		int rounds;
		cin >> rounds;
		for(int round = 0; round < rounds; ++round){
			for(int i = 0; i < p; ++i){
				int x = players[i].posx, y = players[i].posy, d = players[i].dir;
				int nx = x + dx[d], ny = y + dy[d];
				if(nx < 0 || nx >= m || ny < 0 || ny >= n){
					d = (d + 2) % 4;
					nx = x + dx[d];
					ny = y + dy[d];
				}
				players[i].posx = nx;
				players[i].posy = ny;
				players[i].dir = d;
				--map[x][y];
				++map[nx][ny];
			}
			for(int x = 0; x < m; ++x){
				for(int y = 0; y < n; ++y){
					if(map[x][y] > 2){
						for(int i = 0; i < p; ++i){
							if(players[i].posx == x && players[i].posy == y){
								players[i].dir = (players[i].dir + 2) % 4;
							}
						}
					}else if(map[x][y] == 2){
						int p1 = -1, p2 = -1;
						for(int i = 0; i < p; ++i){
							if(players[i].posx == x && players[i].posy == y){
								if(p1 == -1){
									p1 = i;
								}else{
									p2 = i;
								}
							}
						}
						if(players[p1].name.length() < players[p2].name.length()){
							swap(p1, p2);
						}
						swap(players[p1].dir, players[p2].dir);
						players[p2].dir = (players[p2].dir + 2) % 4;
					}
				}
			}
		}
		int max_dist = 10000, max_player = 0;
		for(int i = 1; i < p; ++i){
			int cmp = (players[i].posx - players[0].posx) * (players[i].posx - players[0].posx)
					+ (players[i].posy - players[0].posy) * (players[i].posy - players[0].posy);
			if(cmp < max_dist){
				max_dist = cmp;
				max_player = i;
			}
		}
		cout << "Case " << c << ": " << players[max_player].name << '\n';
	}
	return 0;
}
