#include <cstdio>

bool enough(int required, int *trees, int number, int cut_height){
	long long sum = 0;
	for(int i = 0; i < number; ++i){
		if(trees[i] > cut_height){
			sum += trees[i] - cut_height;
		}
	}
	return sum >= required;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	static int trees[1000000];
	int max = 0, min = 0;
	for(int i = 0; i < n; ++i){
		scanf("%d", &trees[i]);
		if(max < trees[i]){
			max = trees[i];
		}
	}
	while(min < max){
		int mid = (min + max + 1) / 2;
		if(enough(m, trees, n, mid)){
			min = mid;
		}else{
			max = mid-1;
		}
	}
	printf("%d", max);
	return 0;
}
