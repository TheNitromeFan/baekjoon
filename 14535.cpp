#include <cstdio>

int main(){
	int cnt = 0;
	while(true){
		++cnt;
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		int month[13] = {};
		for(int i = 0; i < n; ++i){
			int d, m, y;
			scanf("%d %d %d", &d, &m, &y);
			++month[m];
		}
		printf("Case #%d:\n", cnt);
		printf("Jan:");
		for(int j = 0; j < month[1]; ++j){
			printf("*");
		}
		printf("\n");
		printf("Feb:");
		for(int j = 0; j < month[2]; ++j){
			printf("*");
		}
		printf("\n");
		printf("Mar:");
		for(int j = 0; j < month[3]; ++j){
			printf("*");
		}
		printf("\n");
		printf("Apr:");
		for(int j = 0; j < month[4]; ++j){
			printf("*");
		}
		printf("\n");
		printf("May:");
		for(int j = 0; j < month[5]; ++j){
			printf("*");
		}
		printf("\n");
		printf("Jun:");
		for(int j = 0; j < month[6]; ++j){
			printf("*");
		}
		printf("\n");
		printf("Jul:");
		for(int j = 0; j < month[7]; ++j){
			printf("*");
		}
		printf("\n");
		printf("Aug:");
		for(int j = 0; j < month[8]; ++j){
			printf("*");
		}
		printf("\n");
		printf("Sep:");
		for(int j = 0; j < month[9]; ++j){
			printf("*");
		}
		printf("\n");
		printf("Oct:");
		for(int j = 0; j < month[10]; ++j){
			printf("*");
		}
		printf("\n");
		printf("Nov:");
		for(int j = 0; j < month[11]; ++j){
			printf("*");
		}
		printf("\n");
		printf("Dec:");
		for(int j = 0; j < month[12]; ++j){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
