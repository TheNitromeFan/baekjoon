#include <iostream>
#define MAX 500010

using namespace std;

int dp[MAX][21];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin >> m;
	for(int u = 1; u <= m; ++u){
		cin >> dp[u][0];
	}
	for(int i = 1; i < 21; ++i){
		for(int u = 1; u <= m; ++u){
			dp[u][i] = dp[dp[u][i - 1]][i - 1];
		}
	}
	int q;
	cin >> q;
	for(int a0 = 0; a0 < q; ++a0){
		int n, x;
		cin >> n >> x;
		for(int i = 0; n; ++i){
			if(n % 2 == 1){
				x = dp[x][i];
			}
			n /= 2;
		}
		cout << x << '\n';
	}
	return 0;
}
