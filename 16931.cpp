#include <iostream>
#define MAX 100

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int blocks[MAX][MAX];
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> blocks[i][j];
		}
	}
	int ans = 2 * n * m;
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			for(int k = 0; k < 4; ++k){
				int x = i + dx[k], y = j + dy[k];
				if(!(x >= 0 && x < n && y >= 0 && y < m)){
					ans += blocks[i][j];
				}else if(blocks[x][y] < blocks[i][j]){
					ans += blocks[i][j] - blocks[x][y];
				}
			}
		}
	}
	cout << ans;
	return 0;
}
