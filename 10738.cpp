#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	cin >> k;
	int prices[21];
	for(int i = 1; i <= k; ++i){
		cin >> prices[i];
	}
	int set;
	cin >> set;
	int setItems[4];
	for(int a0 = 0; a0 < 4; ++a0){
		cin >> setItems[a0];
	}
	int m;
	cin >> m;
	int bill = 0;
	int a = 0, b = 0, c = 0, d = 0;
	for(int j = 0; j < m; ++j){
		int x;
		cin >> x;
		if(x == setItems[0]){
			++a;
		}else if(x == setItems[1]){
			++b;
		}else if(x == setItems[2]){
			++c;
		}else if(x == setItems[3]){
			++d;
		}else{
			bill += prices[x];
		}
	}
	while(a > 0 || b > 0 || c > 0 || d > 0){
		int menuPrice = 0;
		if(a > 0){
			--a;
			menuPrice += prices[setItems[0]];
		}
		if(b > 0){
			--b;
			menuPrice += prices[setItems[1]];
		}
		if(c > 0){
			--c;
			menuPrice += prices[setItems[2]];
		}
		if(d > 0){
			--d;
			menuPrice += prices[setItems[3]];
		}
		if(menuPrice > set){
			bill += set;
		}else{
			bill += menuPrice;
		}
	}
	cout << bill;
	return 0;
}
