#include <cstdio>

int main(){
	int ones = 0;
	int x;
	for(int i = 0; i < 3; ++i){
		scanf("%d", &x);
		if(x == 1){
			++ones;
		}
	}
	switch(ones){
		case 2:
		case 3:
			printf("1");
			break;
		case 0:
		case 1:
			printf("2");
	}
	return 0;
}
