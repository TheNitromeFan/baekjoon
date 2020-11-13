#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	bool marked[2001] = {};
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		marked[x+1000] = true;
	}
	for(int i = 0; i < 2001; ++i){
		if(marked[i]){
			printf("%d ", i-1000);
		}
	}
	return 0;
}
