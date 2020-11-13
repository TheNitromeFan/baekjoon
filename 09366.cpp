#include <cstdio>
#include <algorithm>

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; ++i){
		int a[3];
		scanf("%d %d %d", &a[0], &a[1], &a[2]);
		if(a[0] == 0 && a[1] == 0 && a[2] == 0){
			break;
		}
		std::sort(a, a + 3);
		printf("Case #%d: ", i);
		if(a[2] >= a[0] + a[1]){
			printf("invalid!");
		}else if(a[0] == a[1] && a[1] == a[2]){
			printf("equilateral");
		}else if(a[0] == a[1] || a[1] == a[2]){
			printf("isosceles");
		}else{
			printf("scalene");
		}
		printf("\n");
	}
	return 0;
}
