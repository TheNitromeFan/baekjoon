#include <cstdio>

int main(){
	char w;
	int cnt = 0;
	for(int a0 = 0; a0 < 6; ++a0){
		scanf(" %c", &w);
		if(w == 'W'){
			++cnt;
		}
	}
	switch(cnt){
		case 5:
		case 6:
			printf("1");
			break;
		case 3:
		case 4:
			printf("2");
			break;
		case 1:
		case 2:
			printf("3");
			break;
		case 0:
			printf("-1");
			break;
	}
	return 0;
}
