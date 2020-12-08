#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int price[1001], deliv[1001];
	for(int i = 0; i < n; ++i){
		cin >> price[i] >> deliv[i];
	}
	int maxProfit = 0;
	int maxProfitPrice = 0;
	for(int i = 0; i < n; ++i){
		int profit = 0;
		for(int j = 0; j < n; ++j){
			if(price[j] >= price[i] && price[i] >= deliv[j]){
				profit += price[i] - deliv[j];
			}
		}
		if(maxProfit < profit || (maxProfit == profit && maxProfitPrice > price[i])){
			maxProfit = profit;
			maxProfitPrice = price[i];
		}
	}
	cout << maxProfitPrice;
	return 0;
}
