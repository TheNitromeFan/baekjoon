#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	bool taken[101] = {};
	int ans = 0;
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		if(taken[x]){
			++ans;
		}
		taken[x] = true;
	}
	printf("%d", ans);
	return 0;
}
