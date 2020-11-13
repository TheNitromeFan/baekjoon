#include <cstdio>

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int prev;
	scanf("%d", &prev);
	int gifts = 0;
	for(int i = 1; i < n; ++i){
		int cur;
		scanf("%d", &cur);
		if(prev - cur >= k){
			++gifts;
		}
		prev = cur;
	}
	printf("%d", gifts);
	return 0;
}
