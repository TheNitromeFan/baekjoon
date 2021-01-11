#include <iostream>
#define MAX 105

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		bool grid[MAX][MAX] = {};
		for(int i = 0; i < n; ++i){
			int x, y;
			cin >> x >> y;
			grid[x + 1][y + 1] = true;
		}
		int fence = 0;
		for(int i = 0; i + 1 < MAX; ++i){
			for(int j = 0; j < MAX; ++j){
				if(grid[i][j] ^ grid[i + 1][j]){
					++fence;
				}
			}
		}
		for(int j = 0; j + 1 < MAX; ++j){
			for(int i = 0; i < MAX; ++i){
				if(grid[i][j] ^ grid[i][j + 1]){
					++fence;
				}
			}
		}
		cout << fence << '\n';
	}
	return 0;
}
