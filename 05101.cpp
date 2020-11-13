#include <cstdio>
#include <cstdlib>

int main(){
	while(true){
		int a, d, x;
		scanf("%d %d %d", &a, &d, &x);
		if(a == 0 && d == 0 && x == 0){
			break;
		}
		if((x - a) * d > 0 && abs(x - a) % abs(d) == 0){
			printf("%d\n", abs(x - a) / abs(d) + 1);
		}else{
			printf("X\n");
		}
	}
	return 0;
}
