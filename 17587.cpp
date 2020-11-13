#include <cstdio>
#include <cstdlib>

int main(){
	int p, d;
	scanf("%d %d", &p, &d);
	long long ad[1001] = {}, bd[1001] = {};
	for(int i = 0; i < p; ++i){
		int di, ai, bi;
		scanf("%d %d %d", &di, &ai, &bi);
		ad[di] += ai;
		bd[di] += bi;
	}
	long long v = 0, wa = 0, wb = 0;
	for(long long j = 1; j <= d; ++j){
		long long thres = (ad[j] + bd[j]) / 2 + 1;
		char winner;
		long long wastedA, wastedB;
		if(ad[j] >= thres){
			winner = 'A';
			wastedA = ad[j] - thres;
			wastedB = bd[j];
		}else{
			winner = 'B';
			wastedA = ad[j];
			wastedB = bd[j] - thres;
		}
		v += ad[j] + bd[j];
		wa += wastedA;
		wb += wastedB;
		printf("%c %lld %lld\n", winner, wastedA, wastedB);
	}
	printf("%.10lf", (double)abs(wa - wb) / v);
	return 0;
}
