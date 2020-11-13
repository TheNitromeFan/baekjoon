#include <cstdio>
#include <cstring>
#include <cctype>

int a[50];

void subtract(int i){
	if(a[i] <= a[i - 1]){
		a[i - 1] -= a[i];
	}else{
		int j;
		a[i - 1] += 10 - a[i];
		for(j = i - 2; a[j] == 0; --j){
			a[j] = 9;
		}
		--a[j];
	}
}

int main(){
	int t;
	scanf("%d", &t);
	char line[61];
	fgets(line, 60, stdin);
	for(int a0 = 0; a0 < t; ++a0){
		fgets(line, 60, stdin);
		printf("%s", line);
		int i;
		for(i = 0; isdigit(line[i]); ++i){
			a[i] = line[i] - '0';
		}
		while((a[0] != 0 && i > 2) || (a[0] == 0 && i > 3)){
			--i;
			subtract(i);
			if(a[0] != 0){
				printf("%d", a[0]);
			}
			for(int j = 1; j < i; ++j){
				printf("%d", a[j]);
			}
			printf("\n");
		}
		line[strlen(line) - 1] = '\0';
		printf("The number %s ", line);
		if((a[0] != 0 && ((a[0] * 10 + a[1]) % 11 == 0))
		|| (a[0] == 0 && ((a[1] * 10 + a[2]) % 11 == 0))){
			printf("is divisible by 11.\n");
		}else{
			printf("is not divisible by 11.\n");
		}
		printf("\n");
	}
	return 0;
}
