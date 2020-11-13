#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	for(int a0 = 0; a0 < n; ++a0){
		int time[3];
		scanf("%d:%d:%d", &time[0], &time[1], &time[2]);
		int vert[6][3], hor[3][6];
		for(int i = 0; i < 3; ++i){
			for(int j = 5; j >= 0; --j){
				vert[j][i] = time[i] % 2;
				hor[i][j] = time[i] % 2;
				time[i] /= 2;
			}
		}
		for(int j = 0; j < 6; ++j){
			for(int i = 0; i < 3; ++i){
				printf("%d", vert[j][i]);
			}
		}
		printf(" ");
		for(int i = 0; i < 3; ++i){
			for(int j = 0; j < 6; ++j){
				printf("%d", hor[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}
