#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	double score = 0;
	for(int i = 0; i < n; ++i){
		double s;
		int a, t, m;
		scanf("%lf %d %d %d", &s, &a, &t, &m);
		score += s * (a + 1) * (t + m) / a / t / 4;
	}
	int rank = 1;
	int p;
	scanf("%d", &p);
	for(int j = 0; j < p; ++j){
		double cmp;
		scanf("%lf", &cmp);
		if(cmp > score){
			++rank;
		}
	}
	printf("The total score of Younghoon%s is %.2lf.", (20 * rank <= 3 * (p + 1) ? " \"The God\"" : ""), score);
	return 0;
}
