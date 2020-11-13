#include <cstdio>

int main(){
	int cnt = 0;
	while(true){
		++cnt;
		int r;
		scanf("%d", &r);
		if(r == 0){
			break;
		}
		int w, h;
		scanf("%d %d", &w, &h);
		if(4 * r * r >= w * w + h * h){
			printf("Pizza %d fits on the table.\n", cnt);
		}else{
			printf("Pizza %d does not fit on the table.\n", cnt);
		}
	}
	return 0;
}
