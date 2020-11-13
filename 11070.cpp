#include <cstdio>

struct team{
	long long points;
	long long allowed;
	long long w;
} teams[1001];

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= n; ++i){
			teams[i].points = 0;
			teams[i].allowed = 0;
		}
		for(int a1 = 0; a1 < m; ++a1){
			int a, b, p, q;
			scanf("%d %d %d %d", &a, &b, &p, &q);
			teams[a].points += p;
			teams[b].points += q;
			teams[a].allowed += q;
			teams[b].allowed += p;
		}
		long long min = 1001, max = -1;
		for(int i = 1; i <= n; ++i){
			if(teams[i].points == 0 && teams[i].allowed == 0){
				teams[i].w = 0;
			}else{
				teams[i].w = 1000 * teams[i].points * teams[i].points / (teams[i].points * teams[i].points + teams[i].allowed * teams[i].allowed);
			}
			if(teams[i].w < min){
				min = teams[i].w;
			}
			if(teams[i].w > max){
				max = teams[i].w;
			}
		}
		printf("%lld\n%lld\n", max, min);
	}
	return 0;
}
