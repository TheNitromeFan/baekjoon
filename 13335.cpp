#include <cstdio>

int main(){
	int n, w, l;
	scanf("%d %d %d", &n, &w, &l);
	int a[1001];
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
	}
	int bridge[101] = {};
	int idx = 1;
	int time = 0;
	int load = 0;
	while(true){
		++time;
		load -= bridge[1];
		for(int i = 1; i < w; ++i){
			bridge[i] = bridge[i + 1];
		}
		if(idx <= n && load + a[idx] <= l){
			load += a[idx];
			bridge[w] = a[idx];
			++idx;
		}else{
			bridge[w] = 0;
		}
		if(idx > n && load == 0){
			break;
		}
		/*
		for(int i = 1; i <= w; ++i){
			printf("%d ", bridge[i]);
		}
		printf("\n");
		*/
	}
	printf("%d", time);
	return 0;
}
