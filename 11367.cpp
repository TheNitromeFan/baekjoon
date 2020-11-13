#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		char name[15];
		int grade;
		scanf("%s %d", name, &grade);
		printf("%s ", name);
		if(grade >= 97){
			printf("A+");
		}else if(grade >= 90){
			printf("A");
		}else if(grade >= 87){
			printf("B+");
		}else if(grade >= 80){
			printf("B");
		}else if(grade >= 77){
			printf("C+");
		}else if(grade >= 70){
			printf("C");
		}else if(grade >= 67){
			printf("D+");
		}else if(grade >= 60){
			printf("D");
		}else{
			printf("F");
		}
		printf("\n");
	}
	return 0;
}
