#include <cstdio>
#define MAX ((1 << 15) + 1)

int main(){
	int n;
	scanf("%d", &n);
	bool finished[MAX] = {};
	for(int i = 0; i < n - 1; ++i){
		int x;
		scanf("%d", &x);
		finished[x] = true;
	}
	for(int j = 1; j <= n; ++j){
		if(!finished[j]){
			printf("%d", j);
			break;
		}
	}
	return 0;
}
