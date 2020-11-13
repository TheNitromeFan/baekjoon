#include <cstdio>
#include <algorithm>

int main(){
	while(true){
		int a[3];
		scanf("%d %d %d", &a[0], &a[1], &a[2]);
		if(a[0] == 0 && a[1] == 0 && a[2] == 0){
			break;
		}
		std::sort(a, a + 3);
		if(a[2] >= a[0] + a[1]){
			printf("Invalid");
		}else if(a[0] == a[1] && a[1] == a[2]){
			printf("Equilateral");
		}else if(a[0] == a[1] || a[1] == a[2]){
			printf("Isosceles");
		}else{
			printf("Scalene");
		}
		printf("\n");
	}
	return 0;
}
