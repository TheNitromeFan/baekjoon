#include <cstdio>

int main(){
	static int div[10000001] = {};
	for(int i = 1; i <= 10000000; ++i){
		for(int j = 1; j * i <= 10000000; ++j){
			++div[j * i];
		}
	}
	int c;
	scanf("%d", &c);
	for(int a0 = 0; a0 < c; ++a0){
		int low, high;
		scanf("%d %d", &low, &high);
		int maxDivCnt = 0;
		for(int i = low; i <= high; ++i){
			if(maxDivCnt <= div[i]){
				maxDivCnt = div[i];
			}
		}
		printf("%d\n", maxDivCnt);
	}
	return 0;
}
