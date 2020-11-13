#include <cstdio>

int score(double x, double y){
	for(int i = 1; i <= 5; ++i){
		if(x * x + y * y <= 9 * i * i){
			return 100 - 20 * (i - 1);
		}
	}
	return 0;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int score1 = 0, score2 = 0;
		for(int i = 0; i < 3; ++i){
			double x, y;
			scanf("%lf %lf", &x, &y);
			score1 += score(x, y);
		}
		for(int i = 0; i < 3; ++i){
			double x, y;
			scanf("%lf %lf", &x, &y);
			score2 += score(x, y);
		}
		printf("SCORE: %d to %d, ", score1, score2);
		if(score1 > score2){
			printf("PLAYER 1 WINS.\n");
		}else if(score1 < score2){
			printf("PLAYER 2 WINS.\n");
		}else{
			printf("TIE.\n");
		}
	}
	return 0;
}
