#include <cstdio>

int main(){
	while(true){
		int h1, m1, h2, m2;
		scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
		if(h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0){
			break;
		}
		int time = 60 * (h1 + h2) + (m1 + m2);
		int days = time / 60 / 24;
		printf("%02d:%02d", time / 60 % 24, time % 60);
		if(days > 0){
			printf(" +%d", days);
		}
		printf("\n");
	}
	return 0;
}
