#include <iostream>
#include <algorithm>
#define MAX 1001

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int houses[MAX][3];
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j < 3; ++j){
			cin >> houses[i][j];
		}
	}
	int cost[MAX][3] = {}; // cost[i][j]: paint 1~i with i-th house painted j
	int ans = 10000000;
	for(int color = 0; color < 3; ++color){
		for(int j = 0; j < 3; ++j){
			if(j == color){
				cost[1][j] = houses[1][j];
			}else{
				cost[1][j] = 10000000;
			}
		}
		for(int i = 2; i <= n; ++i){
			cost[i][0] = min(cost[i - 1][1], cost[i - 1][2]) + houses[i][0];
			cost[i][1] = min(cost[i - 1][2], cost[i - 1][0]) + houses[i][1];
			cost[i][2] = min(cost[i - 1][0], cost[i - 1][1]) + houses[i][2];
		}
		for(int j = 0; j < 3; ++j){
			if(j != color){
				ans = min(ans, cost[n][j]);
			}
		}
	}
	cout << ans;
	return 0;
}
