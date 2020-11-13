#include <cstdio>
#include <algorithm>
#include <functional>

int main(){
	while(true){
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		int money[1000];
		int sum = 0;
		for(int i = 0; i < n; ++i){
			int d, c;
			scanf("%d.%d", &d, &c);
			money[i] = 100 * d + c;
			sum += money[i];
		}
		std::sort(money, money + n, std::greater<int>());
		int low = sum / n;
		int high = low + 1;
		long long exch = 0;
		int i;
		for(i = 0; i < sum % n; ++i){
			exch += abs(money[i] - high);
		}
		for(; i < n; ++i){
			exch += abs(money[i] - low);
		}
		exch /= 2;
		// printf("%lld\n", exch);
		printf("$%lld.%02lld\n", exch / 100, exch % 100);
	}
	return 0;
}
