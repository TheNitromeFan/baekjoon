#include <iostream>
#define MAXN 21
#define MAXM 21

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int a[MAXN][MAXM];
		int n, m;
		cin >> n >> m;
		int person = n * m;
		for(int diag = 1; diag <= n + m - 1; ++diag){
			for(int i = diag, j = 1; i >= 1; --i, ++j){
				if(i <= n && j <= m){
					a[i][j] = person;
					--person;
				}
			}
		}
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= m; ++j){
				cout << a[i][j] << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}
