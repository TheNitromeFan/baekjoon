#include <cstdio>

struct team{
	int wins;
	int ties;
	int losses;
	int points;
	int rank;
} t[101];

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		t[i].wins = 0;
		t[i].ties = 0;
		t[i].losses = 0;
	}
	for(int match = 0; match < n * (n-1) / 2; ++match){
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if(c < d){
			++t[a].losses;
			++t[b].wins;
		}else if(c > d){
			++t[a].wins;
			++t[b].losses;
		}else{
			++t[a].ties;
			++t[b].ties;
		}
	}
	for(int i = 1; i <= n; ++i){
		t[i].points = 3 * t[i].wins + t[i].ties;
		t[i].rank = 1;
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if(t[j].points > t[i].points){
				++t[i].rank;
			}
		}
	}
	for(int i = 1; i <= n; ++i){
		printf("%d\n", t[i].rank);
	}
	return 0;
}
