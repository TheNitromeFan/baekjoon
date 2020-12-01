#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 1; a0 <= t; ++a0){
		int n;
		scanf("%d", &n);
		int m[1000];
		for(int i = 0; i < n; ++i){
			scanf("%d", &m[i]);
		}
		int maxDec = 0, sumDec = 0;
		for(int i = 0; i + 1 < n; ++i){
			if(m[i] <= m[i + 1]){
				continue;
			}
			int dec = m[i] - m[i + 1];
			if(maxDec < dec){
				maxDec = dec;
			}
			sumDec += dec;
		}
		int eaten = 0;
		for(int i = 0; i + 1 < n; ++i){
			if(m[i] < maxDec){
				eaten += m[i];
			}else{
				eaten += maxDec;
			}
		}
		printf("Case #%d: %d %d\n", a0, sumDec, eaten);
	}
	return 0;
}
