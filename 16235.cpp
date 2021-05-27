#include <iostream>
#include <deque>
#define MAX 11

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	int a[MAX][MAX], b[MAX][MAX];
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			a[i][j] = 5;
			cin >> b[i][j];
		}
	}
	deque<int> trees[MAX][MAX];
	for(int a0 = 0; a0 < m; ++a0){
		int x, y, z;
		cin >> x >> y >> z;
		trees[x][y].push_back(z);
	}
	for(int year = 1; year <= k; ++year){
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				deque<int> surviving;
				int fertilizer = 0;
				while(!trees[i][j].empty()){
					int x = trees[i][j].front();
					trees[i][j].pop_front();
					if(a[i][j] >= x){
						a[i][j] -= x;
						surviving.push_back(x + 1);
					}else{
						fertilizer += x / 2;
					}
				}
				while(!surviving.empty()){
					trees[i][j].push_back(surviving.front());
					surviving.pop_front();
				}
				a[i][j] += fertilizer;
			}
		}
		int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
		int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				for(int x : trees[i][j]){
					if(x % 5 != 0){
						continue;
					}
					for(int k = 0; k < 8; ++k){
						int ni = i + dx[k];
						int nj = j + dy[k];
						if(ni >= 1 && ni <= n && nj >= 1 && nj <= n){
							trees[ni][nj].push_front(1);
						}
					}
				}
			}
		}
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				a[i][j] += b[i][j];
			}
		}
	}
	deque<int>::size_type cnt = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			cnt += trees[i][j].size();
		}
	}
	cout << cnt;
	return 0;
}
