#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int a[1000];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	int votes = 0;
	while(true){
		int max_idx = 0, max_votes = a[0];
		for(int i = 1; i < n; ++i){
			if(a[i] >= max_votes){
				max_idx = i;
				max_votes = a[i];
			}
		}
		if(max_idx == 0){
			printf("%d", votes);
			break;
		}
		++votes;
		++a[0];
		--a[max_idx];
	}
	return 0;
}
