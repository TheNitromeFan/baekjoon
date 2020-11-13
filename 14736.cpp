#include <cstdio>

int main(){
	int n, k, a;
	scanf("%d %d %d", &n, &k, &a);
	int amount = k / a;
	int min_time = 100000000;
	for(int i = 1; i <= n; ++i){
		int t, s;
		scanf("%d %d", &t, &s);
		int breaks, time;
		if(amount % t == 0){
			breaks = amount / t - 1;
			time = (t + s) * breaks + t; 
		}else{
			breaks = amount / t;
			time = (t + s) * breaks + amount % t;
		}
		if(time < min_time){
			min_time = time;
		}
	}
	printf("%d", min_time);
	return 0;
}
