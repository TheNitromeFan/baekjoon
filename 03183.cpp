#include <cstdio>

bool leap(int year){
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int main(){
	while(true){
		int d, m, y;
		scanf("%d %d %d", &d, &m, &y);
		if(d == 0 && m == 0 && y == 0){
			break;
		}
		int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		if(leap(y)){
			days[2] = 29;
		}
		if(m <= 12 && d > 0 && d <= days[m]){
			printf("Valid\n");
		}else{
			printf("Invalid\n");
		}
	}
	return 0;
}
