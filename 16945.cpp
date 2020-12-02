#include <cstdio>
#include <cstdlib>

int dist(int a[][3], int b[][3]){
	int ret = 0;
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			ret += abs(a[i][j] - b[i][j]);
		}
	}
	return ret;
}

int main(){
	int magic_squares[8][3][3] = {{{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
							     {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
							     {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
							     {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},
							     {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
							     {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}},
							     {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},
							     {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}}};
	int a[3][3];
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			scanf("%d", &a[i][j]);
		}
	}
	int minCost = 100000;
	for(int k = 0; k < 8; ++k){
		int cost = dist(a, magic_squares[k]);
		if(minCost > cost){
			minCost = cost;
		}
	}
	printf("%d", minCost);
	return 0;
}
