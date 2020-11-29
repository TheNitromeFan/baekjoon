#include <cstdio>
#include <set>

using std::set;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void search(int a[][5], int x, int y, int depth, int cur, set<int> &found){
	cur = cur * 10 + a[x][y];
	if(depth == 6){
		found.insert(cur);
	}else{
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < 5 && ny >= 0 && ny < 5){
				search(a, nx, ny, depth + 1, cur, found);
			}
		}
	}
}

int main(){
	int a[5][5];
	for(int i = 0; i < 5; ++i){
		for(int j = 0; j < 5; ++j){
			scanf("%d", &a[i][j]);
		}
	}
	set<int> found;
	for(int i = 0; i < 5; ++i){
		for(int j = 0; j < 5; ++j){
			search(a, i, j, 1, 0, found);
		}
	}
	printf("%llu", found.size());
	return 0;
}
