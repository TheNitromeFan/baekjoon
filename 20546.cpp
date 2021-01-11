#include <iostream>
#include <vector>

using namespace std;

int bnp(vector<int> &prices, int money){
	int stocks = 0;
	for(int price : prices){
		stocks += money / price;
		money %= price;
	}
	return money + prices.back() * stocks;
}

int timing(vector<int> &prices, int money){
	int stocks = 0;
	for(int i = 3; i < 14; ++i){
		if(prices[i - 3] < prices[i - 2] && prices[i - 2] < prices[i - 1] && prices[i - 1] < prices[i]){
			money += prices[i] * stocks;
			stocks = 0;
		}else if(prices[i - 3] > prices[i - 2] && prices[i - 2] > prices[i - 1] && prices[i - 1] > prices[i]){
			stocks += money / prices[i];
			money %= prices[i];
		}
	}
	return money + prices.back() * stocks;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int money;
	cin >> money;
	vector<int> prices(14);
	for(int &price : prices){
		cin >> price;
	}
	int b = bnp(prices, money), t = timing(prices, money);
	if(b > t){
		cout << "BNP";
	}else if(b < t){
		cout << "TIMING";
	}else{
		cout << "SAMESAME";
	}
	return 0;
}
