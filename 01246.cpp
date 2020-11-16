#include <cstdio>
#include <algorithm>
#include <functional>

using std::sort;
using std::greater;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	static int p[1000001];
	for(int i = 1; i <= m; ++i){
		scanf("%d", &p[i]);
	}
	sort(p + 1, p + m + 1, greater<int>());
	int price = 0, maxProfit = 0;
	for(int i = 1; i <= n; ++i){
		int profit = i * p[i];
		if(maxProfit <= profit){
			maxProfit = profit;
			price = p[i];
		}
	}
	printf("%d %d", price, maxProfit);
	return 0;
}
