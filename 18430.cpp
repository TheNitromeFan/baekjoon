#include <iostream>
#define MAX 5

using namespace std;

int boomerang(int a[][MAX], bool used[][MAX], int n, int m, int cur){
	if(cur == n * m){
		return 0;
	}
	int ret = boomerang(a, used, n, m, cur + 1);
	int x = cur / m, y = cur % m;
	if(x - 1 >= 0 && y - 1 >= 0 && !used[x][y] && !used[x][y - 1] && !used[x - 1][y]){
		used[x][y] = true;
		used[x][y - 1] = true;
		used[x - 1][y] = true;
		int cmp = 2 * a[x][y] + a[x][y - 1] + a[x - 1][y] + boomerang(a, used, n, m, cur + 1);
		if(ret < cmp){
			ret = cmp;
		}
		used[x][y] = false;
		used[x][y - 1] = false;
		used[x - 1][y] = false;
	}
	if(x - 1 >= 0 && y + 1 < m && !used[x][y] && !used[x][y + 1] && !used[x - 1][y]){
		used[x][y] = true;
		used[x][y + 1] = true;
		used[x - 1][y] = true;
		int cmp = 2 * a[x][y] + a[x][y + 1] + a[x - 1][y] + boomerang(a, used, n, m, cur + 1);
		if(ret < cmp){
			ret = cmp;
		}
		used[x][y] = false;
		used[x][y + 1] = false;
		used[x - 1][y] = false;
	}
	if(x + 1 < n && y - 1 >= 0 && !used[x][y] && !used[x][y - 1] && !used[x + 1][y]){
		used[x][y] = true;
		used[x][y - 1] = true;
		used[x + 1][y] = true;
		int cmp = 2 * a[x][y] + a[x][y - 1] + a[x + 1][y] + boomerang(a, used, n, m, cur + 1);
		if(ret < cmp){
			ret = cmp;
		}
		used[x][y] = false;
		used[x][y - 1] = false;
		used[x + 1][y] = false;
	}
	if(x + 1 < n && y + 1 < m && !used[x][y] && !used[x][y + 1] && !used[x + 1][y]){
		used[x][y] = true;
		used[x][y + 1] = true;
		used[x + 1][y] = true;
		int cmp = 2 * a[x][y] + a[x][y + 1] + a[x + 1][y] + boomerang(a, used, n, m, cur + 1);
		if(ret < cmp){
			ret = cmp;
		}
		used[x][y] = false;
		used[x][y + 1] = false;
		used[x + 1][y] = false;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int a[MAX][MAX];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> a[i][j];
		}
	}
	bool used[MAX][MAX] = {};
	cout << boomerang(a, used, n, m, 0) << '\n';
	return 0;
}
