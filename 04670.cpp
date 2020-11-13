#include <cstdio>

int main(){
	while(true){
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		int m = (n - 1) / 4 + 1;
		int page[25][4] = {};
		int i = 1, p = 1;
		bool up = true;
		while(i <= n){
			if(up){
				if(i % 2 == 0){
					page[p][2] = i;
					if(p == m){
						up = false;
					}else{
						++p;
					}
				}else{
					page[p][1] = i;
				}
			}else{
				if(i % 2 == 0){
					page[p][0] = i;
					--p;
				}else{
					page[p][3] = i;
				}
			}
			++i;
		}
		printf("Printing order for %d pages:\n", n);
		for(int sheet = 1; sheet <= m; ++sheet){
			if(page[sheet][0] != 0 || page[sheet][1] != 0){
				printf("Sheet %d, front: ", sheet);
				if(page[sheet][0] != 0){
					printf("%d", page[sheet][0]);
				}else{
					printf("Blank");
				}
				printf(", ");
				if(page[sheet][1] != 0){
					printf("%d", page[sheet][1]);
				}else{
					printf("Blank");
				}
				printf("\n");
			}
			if(page[sheet][2] != 0 || page[sheet][3] != 0){
				printf("Sheet %d, back : ", sheet);
				if(page[sheet][2] != 0){
					printf("%d", page[sheet][2]);
				}else{
					printf("Blank");
				}
				printf(", ");
				if(page[sheet][3] != 0){
					printf("%d", page[sheet][3]);
				}else{
					printf("Blank");
				}
				printf("\n");
			}
		}
		printf("\n");
	}
	return 0;
}
