#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3){
	int cmp = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
	if(cmp > 0){
		return 1;
	}else if(cmp < 0){
		return -1;
	}else{
		return 0;
	}
}

int main(){
	int h, w;
	scanf("%d %d", &h, &w);
	char map[101][101];
	int dx[4] = {-1, 1, 1, -1};
	int dy[4] = {-1, -1, 1, 1};
	int x = -1, y = -1, dir = -1;
	for(int i = 0; i < h; ++i){
		scanf("%s", map[i]);
		for(int j = 0; j < w; ++j){
			if(map[i][j] == '\\'){
				x = i;
				y = j;
				dir = 2;
			}else if(map[i][j] == '/'){
				x = i + 1;
				y = j;
				dir = 3;
			}
		}
	}
	vector<int> px = {x}, py = {y};
	do{
		x += dx[dir];
		y += dy[dir];
		px.push_back(x);
		py.push_back(y);
		for(int i = -1; i <= 1; ++i){
			int ndir = (dir + i + 4) % 4;
			int nx = x + dx[ndir], ny = y + dy[ndir];
			if(!(nx >= 0 && nx <= h && ny >= 0 && ny <= w)){
				continue;
			}
			if((ndir == 0 && map[nx][ny] == '\\') || (ndir == 1 && map[x][ny] == '/')
			|| (ndir == 2 && map[x][y] == '\\') || (ndir == 3 && map[nx][y] == '/')){
				dir = ndir;
				break;
			}
		}
		// printf("%d %d %d\n", x, y, dir);
	}while(px.front() != px.back() || py.front() != py.back());
	int area = 0;
	int x1 = px[0], y1 = py[0];
	for(unsigned i = 1; i + 1 < px.size(); ++i){
		int x2 = px[i], y2 = py[i], x3 = px[i + 1], y3 = py[i + 1];
		int triangle = abs(x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3);
		area += ccw(x1, y1, x2, y2, x3, y3) * triangle;
	}
	printf("%d", area / 2);
	return 0;
}
