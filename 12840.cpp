#include <cstdio>

int main(){
	int h, m, s;
	scanf("%d %d %d", &h, &m, &s);
	int time = h * 60 * 60 + m * 60 + s;
	int tc;
	scanf("%d", &tc);
	for(int i = 0; i < tc; ++i){
		int t;
		scanf("%d", &t);
		if(t == 3){
			printf("%d %d %d\n", time / 60 / 60, time / 60 % 60, time % 60);
			continue;
		}
		int c;
		scanf("%d", &c);
		if(t == 2){
			time -= c;
			while(time < 0){
				time += 24 * 60 * 60;
			}
		}else{
			time += c;
			while(time >= 24 * 60 * 60){
				time -= 24 * 60 * 60;
			}
		}
	}
	return 0;
}
