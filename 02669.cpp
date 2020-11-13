#include <cstdio>

int main(){
	bool filled[100][100] = {};
	for(int q = 0; q < 4; ++q){
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		for(int i = a; i < c; ++i){
			for(int j = b; j < d; ++j){
				filled[i][j] = true;
			}
		}
	}
	int cnt = 0;
	for(int i = 0; i < 100; ++i){
		for(int j = 0; j < 100; ++j){
			if(filled[i][j]){
				++cnt;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}
