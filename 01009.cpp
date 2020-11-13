#include <cstdio>

int main(){
	int ones[10][10];
	ones[2][1] = 2;
	ones[2][2] = 4;
	ones[2][3] = 8;
	ones[2][0] = 6;
	ones[3][1] = 3;
	ones[3][2] = 9;
	ones[3][3] = 7;
	ones[3][0] = 1;
	ones[4][1] = 4;
	ones[4][0] = 6;
	ones[7][1] = 7;
	ones[7][2] = 9;
	ones[7][3] = 3;
	ones[7][0] = 1;
	ones[8][1] = 8;
	ones[8][2] = 4;
	ones[8][3] = 2;
	ones[8][0] = 6;
	ones[9][1] = 9;
	ones[9][0] = 1;
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		int ans;
		a %= 10;
		if(a == 1 || a == 5 || a == 6){
			ans = a;
		}else if(a == 0){
			ans = 10;
		}else if(a == 4 || a == 9){
			ans = ones[a][b % 2];
		}else{
			ans = ones[a][b % 4];
		}
		printf("%d\n", ans);
	}
	return 0;
}
