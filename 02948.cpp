#include <cstdio>

int main(){
	int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int d, m;
	scanf("%d %d", &d, &m);
	int cd = 1, cm = 1;
	int day = 0;
	while(cm < m){
		day += days[cm];
		++cm;
	}
	while(cd < d){
		++day;
		++cd;
	}
	switch(day % 7){
		case 0:
			printf("Thursday");
			break;
		case 1:
			printf("Friday");
			break;
		case 2:
			printf("Saturday");
			break;
		case 3:
			printf("Sunday");
			break;
		case 4:
			printf("Monday");
			break;
		case 5:
			printf("Tuesday");
			break;
		case 6:
			printf("Wednesday");
			break;
	}
	return 0;
}
