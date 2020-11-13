#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	int ans = 0;
	for(int i = 0; i < 5; ++i){
		int x;
		scanf("%d", &x);
		if(x == t){
			++ans;
		}
	}
	printf("%d", ans);
	return 0;
}
