#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> cows(n);
	int ones = 0, twos = 0, threes = 0;
	for(int i = 0; i < n; ++i){
		cin >> cows[i];
		if(cows[i] == 1){
			++ones;
		}else if(cows[i] == 2){
			++twos;
		}else{
			++threes;
		}
	}
	int twos_in_ones = 0, threes_in_ones = 0, ones_in_threes = 0, twos_in_threes = 0;
	for(int i = 0; i < ones; ++i){
		if(cows[i] == 2){
			++twos_in_ones;
		}else if(cows[i] == 3){
			++threes_in_ones;
		}
	}
	for(int i = ones + twos; i < n; ++i){
		if(cows[i] == 1){
			++ones_in_threes;
		}else if(cows[i] == 2){
			++twos_in_threes;
		}
	}
	int ans = min(threes_in_ones, ones_in_threes);
	threes_in_ones -= ans;
	ones_in_threes -= ans;
	ans += twos_in_ones + threes_in_ones + ones_in_threes + twos_in_threes;
	cout << ans;
	return 0;
}
