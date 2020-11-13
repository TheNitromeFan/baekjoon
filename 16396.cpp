#include <cstdio>
#define MAX (10000 + 1)

int main(){
	int n;
	scanf("%d", &n);
	bool projected[MAX] = {};
	for(int i = 0; i < n; ++i){
		int start, end;
		scanf("%d %d", &start, &end);
		for(int j = start; j < end; ++j){
			projected[j] = true;
		}
	}
	int ans = 0;
	for(int j = 0; j < MAX; ++j){
		if(projected[j]){
			++ans;
		}
	}
	printf("%d", ans);
	return 0;
}
