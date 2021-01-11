#include <iostream>
#include <algorithm>
#include <utility>
#define MAX 2000
#define MAXV 1000000000

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int c, n;
	cin >> c >> n;
	int cost[MAX] = {};
	for(int i = 0; i < MAX; ++i){
		cost[i] = MAXV;
	}
	pair<int, int> p[MAX];
	for(int j = 0; j < n; ++j){
		int price, cust;
		cin >> price >> cust;
		p[j] = make_pair(price, cust);
		cost[cust] = min(cost[cust], price);
	}
	for(int i = 0; i < MAX; ++i){
		for(int j = 0; j < n; ++j){
			int price = p[j].first, cust = p[j].second;
			if(i >= cust){
				cost[i] = min(cost[i], cost[i - cust] + price);
			}
		}
	}
	int ans = MAXV;
	for(int i = c; i < MAX; ++i){
		ans = min(ans, cost[i]);
	}
	cout << ans;
	return 0;
}
