#include <cstdio>

bool is_prime(int x){
	return x == 2 || x == 3 || x == 5 || x == 7 || x == 11 || x == 13 || x == 17;
}

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	double p[19][19][19] = {};
	p[0][0][0] = 1;
	for(int i = 0; i < 18; ++i){
		for(int j = 0; j <= i; ++j){
			for(int k = 0; k <= i; ++k){
				p[i + 1][j + 1][k + 1] += p[i][j][k] * a * b / 10000;
				p[i + 1][j + 1][k] += p[i][j][k] * a * (100 - b) / 10000;
				p[i + 1][j][k + 1] += p[i][j][k] * (100 - a) * b / 10000;
				p[i + 1][j][k] += p[i][j][k] * (100 - a) * (100 - b) / 10000;
			}
		}
	}
	double ans = 0;
	for(int j = 0; j <= 18; ++j){
		for(int k = 0; k <= 18; ++k){
			if(is_prime(j) || is_prime(k)){
				ans += p[18][j][k];
			}
		}
	}
	printf("%.10f", ans);
	return 0;
}
