#include <cstdio>

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

double backtrack(bool map[][29], int p[4], int n, int cur, int posx, int posy){
	if(cur == n){
		return 1.0;
	}
	map[posx][posy] = true;
	double ret = 0;
	for(int i = 0; i < 4; ++i){
		int nposx = posx + dx[i], nposy = posy + dy[i];
		if(!map[nposx][nposy]){
			ret += backtrack(map, p, n, cur + 1, nposx, nposy) * p[i] / 100;
		}
	}
	map[posx][posy] = false;
	return ret;
}

int main(){
	int n;
	int p[4];
	scanf("%d", &n);
	for(int i = 0; i < 4; ++i){
		scanf("%d", &p[i]);
	}
	bool map[29][29] = {};
	printf("%.10f", backtrack(map, p, n, 0, 14, 14));
	return 0;
}
