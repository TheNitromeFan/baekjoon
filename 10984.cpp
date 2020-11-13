#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		scanf("%d", &n);
		int total_c = 0;
		double total_g = 0;
		for(int i = 0; i < n; ++i){
			int c;
			double g;
			scanf("%d %lf", &c, &g);
			total_c += c;
			total_g += c*g;
		}
		printf("%d %.1lf\n", total_c, total_g/total_c);
	}
	return 0;
}
