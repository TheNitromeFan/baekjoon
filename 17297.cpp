#include <cstdio>

int main(){
	int fibs[44] = {0, 5, 13};
	for(int i = 3; i <= 40; ++i){
		fibs[i] = fibs[i-1] + fibs[i-2] + 1;
	}
	const char s[50] = "Messi Gimossi";
	int m;
	scanf("%d", &m);
	--m;
	for(int i = 40; i >= 2; --i){
		if(m >= fibs[i]){
			m -= fibs[i] + 1;
		}
	}
	if(m == 5 || m == -1){
		printf("Messi Messi Gimossi");
	}else{
		printf("%c", s[m]);
	}
	return 0;
}
