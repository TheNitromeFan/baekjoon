#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int b;
		scanf("%d", &b);
		for(int a = 0; a < 256; ++a){
			if(b == (a ^ ((a << 1) % 256))){
				printf("%d ", a);
				break;
			}
		}
	}
	return 0;
}
