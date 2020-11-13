#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int n;
		scanf("%d", &n);
		int ag, ac;
		scanf("%d %d", &ag, &ac);
		for(int j = 1; j < n; ++j){
			int g, c;
			scanf("%d %d", &g, &c);
			if(ag * c < g * ac || (ag * c == g * ac && c < ac)){
				ag = g;
				ac = c;
			}
		}
		printf("%d\n", ac);
	}
	return 0;
}
