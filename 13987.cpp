#include <cstdio>
#include <cmath>

int main(){
	int a[6], b[6];
	for(int i = 0; i < 6; ++i){
		scanf("%d", &a[i]);
	}
	for(int j = 0; j < 6; ++j){
		scanf("%d", &b[j]);
	}
	int wins = 0, ties = 0;
	for(int i = 0; i < 6; ++i){
		for(int j = 0; j < 6; ++j){
			if(a[i] > b[j]){
				++wins;
			}else if(a[i] == b[j]){
				++ties;
			}
		}
	}
	double ans = wins/ (36.0 - ties);
	printf("%.5f", ans * 100000 / 100000);
	return 0;
}
