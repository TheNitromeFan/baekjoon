#include <cstdio>

int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int mod = 1;
	while(mod <= c){
		mod *= 10;
	}
	int cnt = 0;
	while(a != c && cnt <= mod){
		a *= b;
		a %= mod;
		++cnt;
	}
	if(a == c){
		printf("%d", cnt);
	}else{
		printf("NIKAD");
	}
	return 0;
}
