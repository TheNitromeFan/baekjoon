#include <cstdio>
#include <algorithm>

char letters[28] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
	int n, x;
	scanf("%d %d", &n, &x);
	if(x < n || x > 26 * n){
		printf("!");
		return 0;
	}
	while(n){
		--n;
		int idx = std::max(1, x - 26 * n);
		printf("%c", letters[idx]);
		x -= idx;
	}
	return 0;
}
