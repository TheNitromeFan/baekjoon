#include <cstdio>

bool magic(char c[][101], int n){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < i; ++j){
			if(c[i][j] != c[j][i]){
				return false;
			}
		}
	}
	return true;
}

int main(){
	int n;
	scanf("%d", &n);
	char c[101][101];
	for(int i = 0; i < n; ++i){
		scanf("%s", c[i]);
	}
	printf("%s", magic(c, n) ? "YES" : "NO");
	return 0;
}
