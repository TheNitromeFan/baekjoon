#include <iostream>
#define MAX 1001

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
	for(int i = 1; i <= n; ++i){
		int ans = 0;
		for(int j = 1; j <= n; ++j){
			ans |= a[i][j];
		}
		cout << ans << ' ';
	}
	return 0;
}
