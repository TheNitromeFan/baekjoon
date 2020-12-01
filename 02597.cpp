#include <cstdio>

int main(){
	double low = 0, high;
	scanf("%lf", &high);
	double a[3][2];
	for(int i = 0; i < 3; ++i){
		scanf("%lf %lf", &a[i][0], &a[i][1]);
	}
	for(int i = 0; i < 3; ++i){
		if(a[i][0] == a[i][1]){
			continue;
		}
		double fold = (a[i][0] + a[i][1]) / 2;
		if(fold < (low + high) / 2){
			for(int j = 0; j < 3; ++j){
				if(a[j][0] < fold){
					a[j][0] = 2 * fold - a[j][0];
				}
				if(a[j][1] < fold){
					a[j][1] = 2 * fold - a[j][1];
				}
			}
			low = fold;
		}else{
			for(int j = 0; j < 3; ++j){
				if(a[j][0] > fold){
					a[j][0] = 2 * fold - a[j][0];
				}
				if(a[j][1] > fold){
					a[j][1] = 2 * fold - a[j][1];
				}
			}
			high = fold;
		}
	}
	printf("%.1lf", high - low);
	return 0;
}
