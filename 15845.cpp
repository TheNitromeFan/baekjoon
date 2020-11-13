#include <cstdio>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int t[101];
	for(int j = 1; j <= m; ++j){
		scanf("%d", &t[j]);
	}
	int winningTeam = 0;
	int maxProblems = -1;
	for(int i = 1; i <= n; ++i){
		int problems = 0;
		for(int j = 1; j <= m; ++j){
			int x;
			scanf("%d", &x);
			if(x == t[j]){
				++problems;
			}
		}
		if(maxProblems < problems){
			maxProblems = problems;
			winningTeam = i;
		}
	}
	printf("%d", winningTeam);
	return 0;
}
