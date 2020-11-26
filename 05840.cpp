#include <cstdio>

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	static int last[1000001] = {};
	int id = -1;
	for(int i = 1; i <= n; ++i){
		int x;
		scanf("%d", &x);
		if(last[x] != 0 && i - last[x] <= k && x > id){
			id = x;
		}
		last[x] = i;
	}
	printf("%d", id);
	return 0;
}
