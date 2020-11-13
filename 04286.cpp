#include <cstdio>

int main(){
	while(true){
		int n;
		double p;
		scanf("%d %lf", &n, &p);
		if(n == 0 && p == 0){
			break;
		}
		double win = 1 << n;
		for(int k = n - 1; k >= 0; --k){
			double thres = (1 << k) / win;
			if(p >= thres){
				win = (p + 1) / 2 * win;
			}else{
				win = (1 << k) * (thres - p) / (1 - p) + win * (thres + 1) / 2 * (1 - thres) / (1 - p);
			}
		}
		printf("%0.3lf\n", win);
	}
	return 0;
}
