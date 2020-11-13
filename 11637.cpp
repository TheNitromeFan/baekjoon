#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int n;
		scanf("%d", &n);
		int votes[11] = {};
		int max_votes = 0, max_idx = 0, sum = 0;
		for(int idx = 1; idx <= n; ++idx){
			scanf("%d", &votes[idx]);
			if(max_votes < votes[idx]){
				max_idx = idx;
				max_votes = votes[idx];
			}else if(max_votes == votes[idx]){
				max_idx = 0;
			}
			sum += votes[idx];
		}
		if(max_idx != 0 && max_votes * 2 > sum){
			printf("majority winner %d\n", max_idx);
		}else if(max_idx != 0){
			printf("minority winner %d\n", max_idx);
		}else{
			printf("no winner\n");
		}
	}
	return 0;
}
