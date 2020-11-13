#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int cur = 1;
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		if(x == cur){
			++cur;
		}else{
			++cnt;
		}
	}
	printf("%d", cnt);
	return 0;
}
