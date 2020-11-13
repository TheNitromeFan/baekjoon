#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	unsigned n;
	scanf("%u", &n);
	vector<double> prices(n, 0);
	for(unsigned i = 0; i < n; ++i){
		scanf("%lf", &prices[i]);
	}
	sort(prices.begin(), prices.end());
	printf("%.2f", prices[1]);
	return 0;
}
