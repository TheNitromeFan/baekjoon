#include <iostream>
#define MAX 21

using namespace std;

bool floyd_warshall(int a[][MAX], int n, bool del[][MAX]){
	for(int k = 1; k <= n; ++k){
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				if(i == j || j == k || k == i){
					continue;
				}
				if(a[i][j] > a[i][k] + a[k][j]){
					return false;
				}else if(a[i][j] == a[i][k] + a[k][j]){
					del[i][j] = true;
				}
			}
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a[MAX][MAX] = {};
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			cin >> a[i][j];
		}
	}
	bool del[MAX][MAX] = {};
	if(floyd_warshall(a, n, del)){
		int ans = 0;
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				if(!del[i][j]){
					ans += a[i][j];
				}
			}
		}
		ans /= 2;
		cout << ans;
	}else{
		cout << -1;
	}
	return 0;
}
