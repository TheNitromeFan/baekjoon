#include <iostream>
#include <algorithm>
#define MAX 101

using namespace std;

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
	int psum[MAX][MAX] = {};
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			psum[i][j] = psum[i][j - 1] + psum[i - 1][j] - psum[i - 1][j - 1] + a[i][j];
		}
	}
	int ans = -2000000000;
	for(int i1 = 1; i1 <= n; ++i1){
		for(int i2 = 1; i2 <= i1; ++i2){
			for(int j1 = 1; j1 <= n; ++j1){
				for(int j2 = 1; j2 <= j1; ++j2){
					ans = max(ans, psum[i1][j1] - psum[i1][j2 - 1] - psum[i2 - 1][j1] + psum[i2 - 1][j2 - 1]);
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
