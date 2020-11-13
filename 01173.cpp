#include <cstdio>

int main(){
	int n, min, max, t, r;
	scanf("%d %d %d %d %d", &n, &min, &max, &t, &r);
	if(min + t > max){
		printf("-1");
		return 0;
	}
	int time = 0, current = min;
	while(n){
		if(current + t <= max){
			current += t;
			--n;
		}else if(current - r >= min){
			current -= r;
		}else{
			current = min;
		}
		++time;
	}
	printf("%d", time);
	return 0;
}
