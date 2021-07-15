#include <iostream>
#define MAX 33

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n, m, t, p;
		cin >> n >> m >> t >> p;
		if(n == 0 && m == 0 && t == 0 && p == 0){
			break;
		}
		int a[MAX][MAX];
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				a[i][j] = 1;
			}
		}
		for(int a0 = 0; a0 < t; ++a0){
			int d, c;
			cin >> d >> c;
			int b[MAX][MAX] = {};
			if(d == 1){
				for(int i1 = c, i2 = c - 1, i = 0; i1 < n || i2 >= 0; ++i1, --i2, ++i){
					for(int j = 0; j < m; ++j){
						if(i1 < n){
							b[i][j] += a[i1][j];
						}
						if(i2 >= 0){
							b[i][j] += a[i2][j];
						}
					}
				}
			}else{
				for(int j1 = c, j2 = c - 1, j = 0; j1 < m || j2 >= 0; ++j1, --j2, ++j){
					for(int i = 0; i < n; ++i){
						if(j1 < m){
							b[i][j] += a[i][j1];
						}
						if(j2 >= 0){
							b[i][j] += a[i][j2];
						}
					}
				}
			}
			for(int i = 0; i < n; ++i){
				for(int j = 0; j < m; ++j){
					a[i][j] = b[i][j];
				}
			}
		}
		for(int a1 = 0; a1 < p; ++a1){
			int x, y;
			cin >> x >> y;
			cout << a[x][y] << '\n';
		}
	}
	return 0;
}
