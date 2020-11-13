#include <cstdio>
#define MAX (5 + 1)

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int n, m;
		scanf("%d %d", &n, &m);
		int votes[MAX] = {};
		for(int i = 0; i < m; ++i){
			for(int j = 1; j <= n; ++j){
				int x;
				scanf("%d", &x);
				votes[j] += x;
			}
		}
		int ans = 0;
		for(int j = 1; j <= n; ++j){
			if(votes[ans] < votes[j]){
				ans = j;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
