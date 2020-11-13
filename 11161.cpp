#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int m;
		scanf("%d", &m);
		int min = 0;
		int house = 0;
		for(int a1 = 0; a1 < m; ++a1){
			int enter, exit;
			scanf("%d %d", &enter, &exit);
			house += enter - exit;
			if(min > house){
				min = house;
			}
		}
		printf("%d\n", -min);
	}
	return 0;
}
