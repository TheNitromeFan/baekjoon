#include <iostream>
#define MAX 1024

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	bool occupied[MAX][MAX] = {};
	int neighbors[MAX][MAX] = {};
	int comfortable = 0;
	int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
	for(int i = 0; i < n; ++i){
		int x, y;
		cin >> x >> y;
		occupied[x][y] = true;
		if(neighbors[x][y] == 3){
			++comfortable;
		}
		for(int j = 0; j < 4; ++j){
			int nx = x + dx[j], ny = y + dy[j];
			if(nx >= 0 && nx < MAX && ny >= 0 && ny < MAX){
				++neighbors[nx][ny];
				if(occupied[nx][ny] && neighbors[nx][ny] == 3){
					++comfortable;
				}else if(occupied[nx][ny] && neighbors[nx][ny] == 4){
					--comfortable;
				}
			}
		}
		cout << comfortable << '\n';
	}
	return 0;
}
