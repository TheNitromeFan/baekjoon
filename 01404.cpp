#include <cstdio>

int main(){
	int p[8][8] = {};
	for(int i = 0; i < 8; ++i){
		for(int j = i + 1; j < 8; ++j){
			scanf("%d", &p[i][j]);
			p[j][i] = 100 - p[i][j];
		}
	}
	/*
	for(int i = 0; i < 8; ++i){
		for(int j = 0; j < 8; ++j){
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}
	*/
	long long a[8] = {};
	for(int i = 0; i < (1 << 7); ++i){
		int n = i;
		int b[4];
		long long prob = 1;
		for(int j = 0; j < 4; ++j){
			prob *= (n % 2) ? p[2 * j + 1][2 * j] : p[2 * j][2 * j + 1];
			b[j] = (n % 2) ? 2 * j + 1 : 2 * j;
			// printf("%d ", prob);
			n /= 2;
		}
		prob *= (n % 2) ? p[b[1]][b[0]] : p[b[0]][b[1]];
		b[0] = (n % 2) ? b[1] : b[0];
		// printf("%d ", prob);
		n /= 2;
		prob *= (n % 2) ? p[b[3]][b[2]] : p[b[2]][b[3]];
		b[1] = (n % 2) ? b[3] : b[2];
		// printf("%d ", prob);
		n /= 2;
		prob *= (n % 2) ? p[b[1]][b[0]] : p[b[0]][b[1]];
		b[0] = (n % 2) ? b[1] : b[0];
		// printf("%d ", prob);
		// printf("%d\n", b[0]);
		a[b[0]] += prob;
		// printf("%d %d\n", b[0], a[b[0]]);
	}
	for(int i = 0; i < 8; ++i){
		printf("%.10lf ", (double)a[i] / 100000000000000LL);
	}
	return 0;
}
