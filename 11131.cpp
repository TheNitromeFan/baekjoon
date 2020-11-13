#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int n;
		scanf("%d", &n);
		int sum = 0;
		for(int j = 0; j < n; ++j){
			int w;
			scanf("%d", &w);
			sum += w;
		}
		if(sum < 0){
			printf("Left\n");
		}else if(sum > 0){
			printf("Right\n");
		}else{
			printf("Equilibrium\n");
		}
	}
	return 0;
}
