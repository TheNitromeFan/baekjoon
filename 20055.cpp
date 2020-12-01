#include <cstdio>

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int a[201];
	for(int i = 1; i <= 2 * n; ++i){
		scanf("%d", &a[i]);
	}
	bool robot[201] = {};
	int board = 1, leave = n;
	int rot = 0;
	int zeroes = 0;
	while(zeroes < k){
		++rot;
		--board;
		if(board == 0){
			board = 2 * n;
		}
		--leave;
		if(leave == 0){
			leave = 2 * n;
		}
		robot[leave] = false;
		int pos = leave;
		for(int i = 0; i < n - 1; ++i){
			int prevPos = pos - 1;
			if(prevPos == 0){
				prevPos = 2 * n;
			}
			if(robot[prevPos] && !robot[pos] && a[pos] >= 1){
				robot[prevPos] = false;
				robot[pos] = true;
				--a[pos];
				if(a[pos] == 0){
					++zeroes;
				}
			}
			pos = prevPos;
		}
		robot[leave] = false;
		if(!robot[board] && a[board] >= 1){
			robot[board] = true;
			--a[board];
			if(a[board] == 0){
				++zeroes;
			}
		}
	}
	printf("%d", rot);
	return 0;
}
