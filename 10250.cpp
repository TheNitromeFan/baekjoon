#include <cstdio>


int room_number(int height, int width, int number){
	
	return ((number-1) % height + 1) * 100 + (number-1) / height + 1;
}

int main(void){
	
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		int h, w, n;
		scanf("%d %d %d", &h, &w, &n);
		printf("%d\n", room_number(h, w, n));
	}
	return 0;
}
