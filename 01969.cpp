#include <cstdio>

int main(){
	int m, n;
	scanf("%d %d", &m, &n);
	char dna[1001][51];
	for(int i = 0; i < m; ++i){
		scanf("%s", dna[i]);
	}
	int sum = 0;
	for(int j = 0; j < n; ++j){
		int a = 0, c = 0, g = 0, t = 0;
		for(int i = 0; i < m; ++i){
			switch(dna[i][j]){
				case 'A':
					++a;
					break;
				case 'C':
					++c;
					break;
				case 'G':
					++g;
					break;
				case 'T':
					++t;
					break;
			}
		}
		if(a >= c && a >= g && a >= t){
			printf("A");
			sum += c + g + t;
		}else if(c >= a && c >= g && c >= t){
			printf("C");
			sum += a + g + t;
		}else if(g >= a && g >= c && g >= t){
			printf("G");
			sum += a + c + t;
		}else{
			printf("T");
			sum += a + c + g;
		}
	}
	printf("\n%d", sum);
	return 0;
}
