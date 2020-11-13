#include <cstdio>
#include <cstring>
#define MAX 1000

int main(){
	int n;
	scanf("%d", &n);
	int a[MAX];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	int jumps[MAX];
	memset(jumps, -1, sizeof(jumps));
	jumps[0] = 0;
	for(int i = 0; i < n; ++i){
		if(jumps[i] == -1){
			continue;
		}
		int cmp = jumps[i] + 1;
		for(int j = 1; j <= a[i] && i + j < n; ++j){
			if(jumps[i + j] == -1 || jumps[i + j] > cmp){
				jumps[i + j] = cmp;
			}
		}
	}
	printf("%d", jumps[n - 1]);
	return 0;
}
