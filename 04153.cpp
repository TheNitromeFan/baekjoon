#include <cstdio>
#include <algorithm>

int main(){
	int a[3];
	while(true){
		scanf("%d %d %d", &a[0], &a[1], &a[2]);
		if(a[0] == 0){
			break;
		}
		std::sort(a, a+3);
		if(a[2] * a[2] == a[0] * a[0] + a[1] * a[1]){
			printf("right\n");
		}else{
			printf("wrong\n");
		}
	}
	return 0;
}
