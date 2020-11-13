#include <cstdio>

int main(){
	while(true){
		int year;
		scanf("%d", &year);
		if(year == 0){
			break;
		}
		if(year % 4 == 0){
			if(year == 1916 || year == 1940 || year == 1944){
				printf("%d Games cancelled\n", year);
			}else if(year == 2024 || year == 2028){
				printf("%d No city yet chosen\n", year);
			}else if(year >= 1896){
				printf("%d Summer Olympics\n", year);
			}else{
				printf("%d No summer games\n", year);
			}
		}else{
			printf("%d No summer games\n", year);
		}
	}
	return 0;
}
