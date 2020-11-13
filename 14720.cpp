#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int milk = 0;
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		if(x == milk){
			++cnt;
			milk = (milk + 1) % 3;
		}
	}
	printf("%d", cnt);
	return 0;
}
