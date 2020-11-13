#include <cstdio>
#include <cstring>
#include <cmath>
#define MAX (100 + 1)

int main(){
	char s[MAX];
	scanf("%s", s);
	int n = strlen(s);
	int r = (int)sqrt(n);
	while(n % r != 0){
		--r;
	}
	int c = n / r;
	char table[MAX][MAX];
	for(int j = 0; j < c; ++j){
		for(int i = 0; i < r; ++i){
			table[i][j] = s[j * r + i];
		}
	}
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			printf("%c", table[i][j]);
		}
	}
	return 0;
}
