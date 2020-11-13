#include <cstdio>

int main(){
	int h, m, s;
	scanf("%d:%d:%d", &h, &m, &s);
	int start = h * 60 * 60 + m * 60 + s;
	scanf("%d:%d:%d", &h, &m, &s);
	int end = h * 60 * 60 + m * 60 + s;
	int time = end - start;
	if(time <= 0){
		time += 24 * 60 * 60;
	}
	printf("%02d:%02d:%02d", time / 60 / 60, time / 60 % 60, time % 60);
	return 0;
}
