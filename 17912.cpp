#include <cstdio>
#define MAX 100000

int main(){
	int n;
	scanf("%d", &n);
	int asteroids[MAX] = {};
	int min = 1000000000;
	int day = 0;
	for(int i = 0; i < n; ++i){
		scanf("%d", &asteroids[i]);
		if(asteroids[i] < min){
			min = asteroids[i];
			day = i;
		}
	}
	printf("%d", day);
	return 0;
}
