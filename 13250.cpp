#include <cstdio>
#define MAX (1000000 + 1)

int main(){
	int n;
	scanf("%d", &n);
	static double d[MAX] = {};
	d[1] = 1;
	d[2] = d[1] / 6 + 1;
	d[3] = (d[1] + d[2]) / 6 + 1;
	d[4] = (d[1] + d[2] + d[3]) / 6 + 1;
	d[5] = (d[1] + d[2] + d[3] + d[4]) / 6 + 1;
	d[6] = (d[1] + d[2] + d[3] + d[4] + d[5]) / 6 + 1;
	for(int i = 7; i <= n; ++i){
		d[i] = (d[i - 6] + d[i - 5] + d[i - 4] + d[i - 3] + d[i - 2] + d[i - 1]) / 6 + 1;
	}
	printf("%0.10f", d[n]);
	return 0;
}
