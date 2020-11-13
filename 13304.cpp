#include <cstdio>

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int a[5] = {};
	for(int i = 0; i < n; ++i){
		int sex, year;
		scanf("%d %d", &sex, &year);
		if(year == 1 || year == 2){
			++a[0];
		}else if((year == 3 || year == 4) && sex == 0){
			++a[1];
		}else if(year == 3 || year == 4){
			++a[2];
		}else if((year == 5 || year == 6) && sex == 0){
			++a[3];
		}else{
			++a[4];
		}
	}
	int sum = 0;
	for(int j = 0; j < 5; ++j){
		if(a[j] % k == 0){
			sum += a[j] / k;
		}else{
			sum += a[j] / k + 1;
		}
	}
	printf("%d", sum);
	return 0;
}
