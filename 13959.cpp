#include <cstdio>

int main(){
	int d, r, t;
	scanf("%d %d %d", &d, &r, &t);
	for(int c = 0; c <= r; ++c){
		for(int n = 0; n <= 100; ++n){
			if(r - c == (n + 8) * (n + 1) / 2 && t + c == (n - d + 7) * (n - d + 2) / 2){
				printf("%d", c);
				return 0;
			}
		}
	}
	return 0;
}
