#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int houses[1000][3], costs[1000][3];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < 3; ++j){
			scanf("%d", &houses[i][j]);
		}
	}
	costs[0][0] = houses[0][0];
	costs[0][1] = houses[0][1];
	costs[0][2] = houses[0][2];
	for(int i = 1; i < n; ++i){
		costs[i][0] = min(costs[i-1][1], costs[i-1][2]) + houses[i][0];
		costs[i][1] = min(costs[i-1][0], costs[i-1][2]) + houses[i][1];
		costs[i][2] = min(costs[i-1][0], costs[i-1][1]) + houses[i][2];
	}
	printf("%d", min(min(costs[n-1][0], costs[n-1][1]), costs[n-1][2]));
	return 0;
}
