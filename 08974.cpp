#include <cstdio>

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	int ans = 0;
	int current = 1, cnt = 0;
	for(int i = 1; i <= b; ++i){
		++cnt;
		if(i >= a){
			ans += current;
		}
		if(cnt == current){
			++current;
			cnt = 0;
		}
	}
	printf("%d", ans);
	return 0;
}
