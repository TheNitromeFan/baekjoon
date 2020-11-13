#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int minIndex = 0, minTurns = 1000000000;
	for(int i = 1; i <= n; ++i){
		int j, m;
		scanf("%d %d", &j, &m);
		int turns = 1 + (j - 1) / (m + 1) * 2 + 1;
		if(minTurns > turns){
			minTurns = turns;
			minIndex = i;
		}
	}
	printf("%d %d", minIndex, minTurns);
	return 0;
}
