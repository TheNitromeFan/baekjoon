#include <cstdio>

int gcd(int a, int b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

int main(){
	int a[6], b[6];
	for(int i = 0; i < 6; ++i){
		scanf("%d", &a[i]);
	}
	for(int j = 0; j < 6; ++j){
		scanf("%d", &b[j]);
	}
	int win = 0;
	for(int i = 0; i < 6; ++i){
		for(int j = 0; j < 6; ++j){
			if(a[i] > b[j]){
				++win;
			}
		}
	}
	int g = gcd(win, 36);
	printf("%d/%d", win / g, 36 / g);
	return 0;
}
