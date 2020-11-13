#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int fee = 0;
	for(int i = 0; i < n; ++i){
		int h, m, d;
		scanf("%d:%d %d", &h, &m, &d);
		int time = h * 60 + m;
		while(d > 0){
			if(time >= 7 * 60 && time < 19 * 60){
				fee += 10;
			}else{
				fee += 5;
			}
			++time;
			time %= 24 * 60;
			--d;
		}
	}
	printf("%d", fee);
	return 0;
}
