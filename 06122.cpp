#include <cstdio>

int main(){
	int n, nlines;
	scanf("%d %d", &n, &nlines);
	int time[146] = {}, start[146] = {};
	for(int i = 0; i < nlines; ++i){
		int c, h, m;
		char keyword[7];
		scanf("%d %s %d %d", &c, keyword, &h, &m);
		int t = 60 * h + m;
		if(keyword[2] == 'A'){
			start[c] = t;
		}else{
			time[c] += t - start[c];
		}
	}
	for(int j = 1; j <= n; ++j){
		printf("%d %d\n", time[j] / 60, time[j] % 60);
	}
	return 0;
}
