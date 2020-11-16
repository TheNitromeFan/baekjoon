#include <cstdio>

using namespace std;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	static bool ice[201][201][201] = {};
	for(int i = 0; i < m; ++i){
		int x, y;
		scanf("%d %d", &x, &y);
		for(int z = 1; z <= n; ++z){
			if(z == x || z == y){
				continue;
			}
			ice[x][y][z] = true;
			ice[y][x][z] = true;
			ice[x][z][y] = true;
			ice[y][z][x] = true;
			ice[z][x][y] = true;
			ice[z][y][x] = true;
		}
	}
	int cnt = 0;
	for(int a = 1; a <= n; ++a){
		for(int b = 1; b < a; ++b){
			for(int c = 1; c < b; ++c){
				if(!ice[a][b][c]){
					++cnt;
				}
			}
		}
	}
	printf("%d", cnt);
	return 0;
}
