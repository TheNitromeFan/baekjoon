#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, budget;
	cin >> n >> budget;
	vector<pair<int, int>> gifts(n);
	for(int i = 0; i < n; ++i){
		cin >> gifts[i].first >> gifts[i].second;
	}
	sort(gifts.begin(), gifts.end(), [](pair<int, int> a, pair<int, int> b){
		return make_pair(a.first + a.second, a.first) < make_pair(b.first + b.second, b.first);
	});
	int idx = 0;
	int max_discount = 0;
	while(idx < n){
		pair<int, int> gift = gifts[idx];
		max_discount = max(max_discount, gift.first / 2);
		if(budget < gift.first + gift.second){
			break;
		}
		budget -= gift.first + gift.second;
		++idx;
	}
	int idx1 = idx;
	while(idx1 < n){
		pair<int, int> gift = gifts[idx1];
		max_discount = max(max_discount, gift.first / 2);
		if(budget + max_discount >= gift.first + gift.second){
			++idx;
			break;
		}
		++idx1;
	}
	cout << idx << '\n';
	return 0;
}
