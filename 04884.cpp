#include <cstdio>

int main(){
	while(true){
		long long g, t, a, d;
		scanf("%lld %lld %lld %lld", &g, &t, &a, &d);
		if(g == -1 && t == -1 && a == -1 && d == -1){
			break;
		}
		long long games = g * (t * (t - 1) / 2);
		long long teams = g * a + d;
		long long powOf2 = 1;
		while(powOf2 < teams){
			powOf2 *= 2;
		}
		long long y = powOf2 - teams;
		teams = powOf2;
		games += teams - 1;
		printf("%lld*%lld/%lld+%lld=%lld+%lld\n", g, a, t, d, games, y);
	}
	return 0;
}
