#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 1; a0 <= t; ++a0){
		int m;
		scanf("%d", &m);
		printf("Case %d:\n", a0);
		for(int i = 0; i < m; ++i){
			int grade;
			scanf("%d", &grade);
			if(grade < 6){
				printf("%d\n", grade + 1);
			}
		}
	}
	return 0;
}
