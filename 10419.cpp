#include <cstdio>
#include <cmath>

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int n;
		scanf("%d", &n);
		printf("%d\n", (int)((sqrt(4 * n + 1) - 1) / 2));
	}
	return 0;
}
