#include <cstdio>

int main(){
	int a[16];
	for(int i = 0; i < 16; i += 2){
		a[i] = getchar() - '0';
	}
	getchar();
	for(int i = 1; i < 16; i += 2){
		a[i] = getchar() - '0';
	}
	for(int len = 16; len > 2; --len){
		for(int i = 0; i < len - 1; ++i){
			a[i] = (a[i] + a[i + 1]) % 10;
		}
	}
	printf("%d%d", a[0], a[1]);
	return 0;
}
