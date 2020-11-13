#include <cstdio>
#include <limits>

int main(){
	int d, n;
	scanf("%d %d", &d, &n);
	static int oven[300001], m[300001];
	int running_min = std::numeric_limits<int>::max();
	for(int i = 1; i <= d; ++i){
		scanf("%d", &oven[i]);
		if(oven[i] < running_min){
			running_min = oven[i];
		}
		m[i] = running_min;
		// printf("%d ", m[i]);
	}
	// printf("\n");
	static int pizza[300001];
	for(int j = 1; j <= n; ++j){
		scanf("%d", &pizza[j]);
	}
	int oven_index = d, pizza_index = 1;
	while(oven_index > 0){
		if(m[oven_index] >= pizza[pizza_index]){
			++pizza_index;
			if(pizza_index > n){
				printf("%d", oven_index);
				return 0;
			}
		}
		--oven_index;
		// printf("%d %d\n", pizza_index, oven_index);
	}
	printf("0");
	return 0;
}
