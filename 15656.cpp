#include <cstdio>
#include <algorithm>

int to_print[8];
int num[8];

void backtrack(int n, int m, int len){
	if(len == m){
		for(int i = 0; i < m; ++i){
			printf("%d ", to_print[i]);
		}
		printf("\n");
		return;
	}
	for(int i = 0; i < n; ++i){
		to_print[len] = num[i];
		backtrack(n, m, len+1);
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i){
		scanf("%d", &num[i]);
	}
	std::sort(num, num+n);
	backtrack(n, m, 0);
	return 0;
}
