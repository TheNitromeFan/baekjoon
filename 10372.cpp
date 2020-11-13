#include <cstdio>

void find_time(int n){
	int lights[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	for(int h = 0; h < 24; ++h){
		for(int m = 0; m < 60; ++m){
			int a = h / 10, b = h % 10, c = m / 10, d = m % 10;
			if(lights[a] + lights[b] + lights[c] + lights[d] == n){
				printf("%d%d:%d%d", a, b, c, d);
				return;
			}
		}
	}
	printf("Impossible");
}

int main(){
	int n;
	scanf("%d", &n);
	find_time(n);
	return 0;
}

/*
int main(){
	int n;
	scanf("%d", &n);
	if(n >= 8 && n <= 25){
		int minutes[13] = {0, 0, 0, 0, 11, 17, 14, 15, 16, 18, 22, 26, 28};
		int hours[14] = {0, 0, 0, 0, 11, 17, 14, 12, 10, 7, 4, 5, 6, 8};
		int m, h;
		if(n <= 16){
			m = 4;
			h = n - 4;
		}else{
			m = n - 13;
			h = 13;
		}
		printf("%02d:%02d", hours[h], minutes[m]);
	}else{
		printf("Impossible");
	}
	return 0;
}
*/
