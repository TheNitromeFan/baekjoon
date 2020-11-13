#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int n;
		scanf("%d", &n);
		int spots[20];
		int max = 0, min = 100;
		for(int i = 0; i < n; ++i){
			scanf("%d", &spots[i]);
			if(spots[i] < min){
				min = spots[i];
			}
			if(spots[i] > max){
				max = spots[i];
			}
		}
		printf("%d\n", 2 * (max - min));
	}
	return 0;
}
