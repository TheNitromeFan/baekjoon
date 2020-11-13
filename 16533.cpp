#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int prev;
	scanf("%d", &prev);
	int piles = 1;
	for(int i = 1; i < n; ++i){
		int cur;
		scanf("%d", &cur);
		if(prev < cur){
			++piles;
		}
		prev = cur;
	}
	printf("%d", piles);
	return 0;
}
