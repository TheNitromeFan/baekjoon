#include <cstdio>
#include <cstring>
#include <cmath>

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		char s[10001];
		scanf("%s", s);
		int len = (int)sqrt(strlen(s));
		char t[100][101] = {};
		for(int i = 0; i < len; ++i){
			for(int j = 0; j < len; ++j){
				t[i][j] = s[i * len + j];
			}
		}
		for(int j = len - 1; j >= 0; --j){
			for(int i = 0; i < len; ++i){
				printf("%c", t[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}
