#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int d, n, s, p;
		scanf("%d %d %d %d", &d, &n, &s, &p);
		if(d < n * (s - p)){
			printf("parallelize\n");
		}else if(d > n * (s - p)){
			printf("do not parallelize\n");
		}else{
			printf("does not matter\n");
		}
	}
	return 0;
}
