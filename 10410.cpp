#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		char name[31];
		int y1, m1, d1, y2, m2, d2, courses;
		scanf("%s %d/%d/%d %d/%d/%d %d", name, &y1, &m1, &d1, &y2, &m2, &d2, &courses);
		printf("%s ", name);
		if(y1 >= 2010 || y2 >= 1991){
			printf("eligible");
		}else if(courses >= 41){
			printf("ineligible");
		}else{
			printf("coach petitions");
		}
		printf("\n");
	}
	return 0;
}
