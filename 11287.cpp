#include <cstdio>

int main(){
	int sum = 0;
	int t[4][6];
	int time[6];
	for(int a0 = 0; a0 < 2; ++a0){
		for(int i = 0; i < 4; ++i){
			for(int j = 0; j < 6; ++j){
				scanf("%d", &t[i][j]);
			}
		}
		for(int j = 0; j < 6; ++j){
			time[j] = t[0][j] * 8 + t[1][j] * 4 + t[2][j] * 2 + t[3][j];
		}
		sum += (10 * time[0] + time[1]) * 60 * 60 + (10 * time[2] + time[3]) * 60 + 10 * time[4] + time[5];
	}
	time[0] = sum / 60 / 60 % 24 / 10;
	time[1] = sum / 60 / 60 % 24 % 10;
	time[2] = sum / 60 % 60 / 10;
	time[3] = sum / 60 % 10;
	time[4] = sum % 60 / 10;
	time[5] = sum % 10;
	for(int j = 0; j < 6; ++j){
		for(int i = 3; i >= 0; --i){
			t[i][j] = time[j] % 2;
			time[j] /= 2;
		}
	}
	for(int i = 0; i < 4; ++i){
		for(int j = 0; j < 6; ++j){
			printf("%d ", t[i][j]);
		}
		printf("\n");
	}
	return 0;
}
