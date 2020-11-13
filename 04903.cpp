#include <cstdio>

int main(){
	long long c[21][21] = {};
	c[0][0] = 1;
	for(int i = 1; i <= 20; ++i){
		for(int j = 0; j <= i; ++j){
			if(j == 0 || j == i){
				c[i][j] = 1;
			}else{
				c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			}
		}
	}
	while(true){
		int a, b;
		scanf("%d %d", &a, &b);
		if(a == -1 && b == -1){
			break;
		}
		if(a + b == c[a + b][b]){
			printf("%d+%d=%d\n", a, b, a + b);
		}else{
			printf("%d+%d!=%d\n", a, b, a + b);
		}
	}
	return 0;
}
