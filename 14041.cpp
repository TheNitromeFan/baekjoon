#include <cstdio>

int main(){
	int h, m;
	scanf("%d:%d", &h, &m);
	int time = h * 60 + m;
	int dist = 240;
	while(dist > 0){
		if((time >= 7 * 60 && time < 10 * 60) || (time >= 15 * 60 && time < 19 * 60)){
			dist -= 1;
		}else{
			dist -= 2;
		}
		++time;
	}
	h = time / 60 % 24, m = time % 60;
	printf("%02d:%02d", h, m);
	return 0;
}
