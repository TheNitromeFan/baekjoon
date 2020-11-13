#include <cstdio>

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int maxSafe = 1, minBroken = k;
	for(int i = 0; i < n; ++i){
		int floor;
		char state[10];
		scanf("%d %s", &floor, state);
		if(state[0] == 'S' && maxSafe < floor){
			maxSafe = floor;
		}else if(state[0] == 'B' && minBroken > floor){
			minBroken = floor;
		}
	}
	printf("%d %d", maxSafe + 1, minBroken - 1);
	return 0;
}
