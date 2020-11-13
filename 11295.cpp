#include <cstdio>

int main(){
	int cnt = 0;
	while(true){
		++cnt;
		int stride;
		scanf("%d", &stride);
		if(stride == 0){
			break;
		}
		printf("User %d\n", cnt);
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			int steps;
			scanf("%d", &steps);
			printf("%.5f\n", stride * steps / 100000.0);
		}
	}
	return 0;
}
