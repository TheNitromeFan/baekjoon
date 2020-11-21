#include <cstdio>

bool mow(char field[][51], int i1, int i2, int j1, int j2){
	for(int i = i1; i <= i2; ++i){
		for(int j = j1; j <= j2; ++j){
			if(field[i][j] == 'W' || field[i][j] == 'R' || field[i][j] == 'T'){
				return false;
			}
		}
	}
	return true;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int a0 = 1; a0 <= n; ++a0){
		int l, w;
		scanf("%d %d", &l, &w);
		char field[51][51];
		for(int i = 0; i < w; ++i){
			scanf("%s", field[i]);
		}
		int maxArea = 0;
		for(int i1 = 0; i1 < w; ++i1){
			for(int i2 = i1; i2 < w; ++i2){
				for(int j1 = 0; j1 < l; ++j1){
					for(int j2 = j1; j2 < l; ++j2){
						int area = (i2 - i1 + 1) * (j2 - j1 + 1);
						if(mow(field, i1, i2, j1, j2) && maxArea < area){
							maxArea = area;
						}
					}
				}
			}
		}
		printf("Case #%d: %d\n", a0, maxArea);
	}
	return 0;
}
