#include <cstdio>
#include <cstdlib>

int main(){
	int w0, l0, t;
	scanf("%d %d %d", &w0, &l0, &t);
	int b0 = l0;
	int d, l, a;
	scanf("%d %d %d", &d, &l, &a);
	int w = w0 + (l - b0 - a) * d;
	if(w > 0){
		printf("%d %d\n", w, b0);
	}else{
		printf("Danger Diet\n");
	}
	w = w0;
	int b = b0;
	for(int i = 1; i <= d; ++i){
		w += l - b - a;
		if(abs(l - b - a) > t){
			if(l - b - a < 0 && -(l - b - a) % 2 == 1){
				b += (l - b - a) / 2 - 1;
			}else{
				b += (l - b - a) / 2;
			}
		}
		if(w <= 0 || b <= 0){
			printf("Danger Diet");
			break;
		}
	}
	if(w > 0 && b > 0){
		printf("%d %d ", w, b);
		if(l0 - b > 0){
			printf("YOYO");
		}else{
			printf("NO");
		}
	}
	return 0;
}
