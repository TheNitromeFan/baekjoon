#include <cstdio>

int main(){
	int time;
	scanf("%d", &time);
	int m;
	scanf("%d\n", &m);
	double adj[4][4] = {};
	for(int i = 0; i < m; ++i){
		char src = getchar();
		getchar();
		char dest = getchar();
		getchar();
		double chance;
		scanf("%lf\n", &chance);
		adj[src - 'A'][dest - 'A'] = chance;
	}
	double p[4] = {0.25, 0.25, 0.25, 0.25};
	for(int t = 0; t < time; ++t){
		double np[4] = {};
		for(int i = 0; i < 4; ++i){
			for(int j = 0; j < 4; ++j){
				np[j] += p[i] * adj[i][j];
			}
		}
		for(int i = 0; i < 4; ++i){
			p[i] = np[i];
		}
	}
	for(int i = 0; i < 4; ++i){
		printf("%f\n", 100 * p[i]);
	}
	return 0;
}
