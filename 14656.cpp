#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int cnt = 0;
	for(int i = 1; i <= n; ++i){
		int x;
		scanf("%d", &x);
		if(x != i){
			++cnt;
		}
	}
	printf("%d", cnt);
	return 0;
}
