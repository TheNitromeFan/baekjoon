#include <cstdio>

int main(){
	while(true){
		int b, g;
		scanf("%d %d", &b, &g);
		if(b == 0 && g == 0){
			break;
		}
		printf("%d\n", b + g);
	}
	return 0;
}
