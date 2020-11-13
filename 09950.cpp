#include <cstdio>

int main(){
	while(true){
		int h, w, a;
		scanf("%d %d %d", &h, &w, &a);
		if(h == 0 && w == 0 && a == 0){
			break;
		}
		if(h && w){
			a = h * w;
		}else if(h && a){
			w = a / h;
		}else{
			h = a / w;
		}
		printf("%d %d %d\n", h, w, a);
	}
	return 0;
}
