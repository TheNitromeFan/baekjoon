#include <iostream>

using namespace std;

int money[6] = {1, 5, 10, 50, 100, 500};

int coins[1000] = {0};

int count(int x){
	if(coins[x] != 0){
		return coins[x];
	}
  	for(int i = 0; i < 6 && x-money[i] > 0; ++i){
		int y = count(x-money[i]);
		if(coins[x] == 0 || coins[x] > y+1){
			coins[x] = y+1;
		}
	}
	return coins[x];
}

int main(){
	int price;
	cin >> price;
	int change = 1000 - price;
	for(int i = 0; i < 6; ++i){
		coins[money[i]] = 1;
	}
	cout << count(change) << endl;
	return 0;
}
