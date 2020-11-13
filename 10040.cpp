#include <cstdio>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int a[1001];
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
	}
	int b[1000];
	int votes[1001] = {};
	for(int j = 0; j < m; ++j){
		scanf("%d", &b[j]);
		for(int i = 1; i <= n; ++i){
			if(a[i] <= b[j]){
				++votes[i];
				break;
			}
		}
	}
	int max_i = 0;
	for(int i = 1; i <= n; ++i){
		if(votes[i] > votes[max_i]){
			max_i = i;
		}
	}
	printf("%d", max_i);
	return 0;
}
