#include <iostream>
#include <algorithm>
#define MAX (20 + 1)

using namespace std;

int max_diff(int a[5]){
	int max_val = 0, min_val = 2000000000;
	for(int i = 0; i < 5; ++i){
		max_val = max(max_val, a[i]);
		min_val = min(min_val, a[i]);
	}
	return max_val - min_val;
}

int gerrymander(int a[][MAX], int n, int x, int y, int d1, int d2){
	int val[5] = {};
	bool b[MAX][MAX] = {};
	for(int i = x; i <= x + d1 + d2; ++i){
		for(int j = max(y - (i - x), y - d1 + d2 - (x + d1 + d2 - i)); j <= min(y + (i - x), y - d1 + d2 + (x + d1 + d2 - i)); ++j){
			val[0] += a[i][j];
			b[i][j] = true;
		}
	}
	for(int i = 1; i < x + d1; ++i){
		for(int j = 1; j <= y; ++j){
			if(!b[i][j]){
				val[1] += a[i][j];
			}
		}
	}
	for(int i = 1; i <= x + d2; ++i){
		for(int j = y + 1; j <= n; ++j){
			if(!b[i][j]){
				val[2] += a[i][j];
			}
		}
	}
	for(int i = x + d1; i <= n; ++i){
		for(int j = 1; j < y - d1 + d2; ++j){
			if(!b[i][j]){
				val[3] += a[i][j];
			}
		}
	}
	for(int i = x + d2 + 1; i <= n; ++i){
		for(int j = y - d1 + d2; j <= n; ++j){
			if(!b[i][j]){
				val[4] += a[i][j];
			}
		}
	}
	return max_diff(val);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a[MAX][MAX];
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			cin >> a[i][j];
		}
	}
	int ans = 2000000000;
	for(int x = 1; x <= n; ++x){
		for(int y = 1; y <= n; ++y){
			for(int d1 = 1; d1 <= n; ++d1){
				for(int d2 = 1; d2 <= n; ++d2){
					if(x + d1 + d2 <= n && y - d1 >= 1 && y + d2 <= n){
						ans = min(ans, gerrymander(a, n, x, y, d1, d2));
					}
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
