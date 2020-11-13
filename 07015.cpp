#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	for(int a0 = 0; a0 < n; ++a0){
		int y, m, d;
		scanf("%d %d %d", &y, &m, &d);
		int days = 0;
		int days_in_month = ((y % 3 == 0 || m % 2 == 1) ? 20 : 19);
		for(; d <= days_in_month; ++d){
			++days;
		}
		++m;
		for(; m <= 10; ++m){
			days += ((y % 3 == 0 || m % 2 == 1) ? 20 : 19);
		}
		++y;
		for(; y < 1000; ++y){
			days += (y % 3 == 0 ? 200 : 195);
		}
		printf("%d\n", days);
	}
	return 0;
}
