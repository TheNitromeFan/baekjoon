#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int ones = 0;
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		if(x == 1){
			++ones;
		}
	}
	printf("%d", n - ones);
	return 0;
}
