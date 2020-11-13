#include <cstdio>
#include <cassert>
#include <utility>
#define MAX 100

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

bool map[MAX+1][MAX+1];

pair<int, int> draw_curve(pair<int, int> p, int dir, int gen){
	int x = p.first, y = p.second;
	if(gen == 0){
		int nx = x + dx[dir], ny = y + dy[dir];
		map[x][y] = true;
		map[nx][ny] = true;
		return make_pair(nx, ny);
	}
	pair<int, int> pivot = draw_curve(p, dir, gen - 1);
	int px = pivot.first, py = pivot.second;
	int nx = px - (y - py), ny = py - (px - x);
	pair<int, int> end = make_pair(nx, ny);
	pair<int, int> pivot1 = draw_curve(end, (dir + 3) % 4, gen - 1);
	assert(pivot1.first == px && pivot1.second == py);
	return end;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int x, y, d, g;
		scanf("%d %d %d %d", &x, &y, &d, &g);
		draw_curve(make_pair(x, y), d, g);
	}
	int ans = 0;
	for(int x = 0; x < MAX; ++x){
		for(int y = 0; y < MAX; ++y){
			if(map[x][y] && map[x][y + 1] && map[x + 1][y] && map[x + 1][y + 1]){
				++ans;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
