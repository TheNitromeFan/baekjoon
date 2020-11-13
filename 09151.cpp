#include <cstdio>

int main(){
	int cubic[55] = {}, tetra[97] = {};
	for(int i = 1; i <= 54; ++i){
		cubic[i] = i * i * i;
	}
	for(int j = 1; j <= 96; ++j){
		tetra[j] = (j * (j + 1) * (j + 2)) / 6;
	}
	while(true){
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		int max = 0;
		for(int i = 0; cubic[i] <= n; ++i){
			for(int j = 0; cubic[i] + tetra[j] <= n; ++j){
				int x = cubic[i] + tetra[j];
				if(max < x){
					max = x;
				}
			}
		}
		printf("%d\n", max);
	}
	return 0;
}
