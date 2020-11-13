#include <cstdio>

int main(){
	while(true){
		int n;
		scanf("%d", &n);
		if(n == -1){
			break;
		}
		int speed, time;
		int ans = 0;
		int prev_time = 0;
		for(int i = 0; i < n; ++i){
			scanf("%d %d", &speed, &time);
			ans += speed * (time - prev_time);
			prev_time = time;
		}
		printf("%d miles\n", ans);
	}
	return 0;
}
