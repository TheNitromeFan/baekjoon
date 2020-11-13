#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <map>

using namespace std;

map<int, int> cnt;

bool cmp(tuple<int, string, int> a, tuple<int, string, int> b){
	return cnt[get<2>(a)] < cnt[get<2>(b)] || (cnt[get<2>(a)] == cnt[get<2>(b)] && (get<2>(a) < get<2>(b) || (get<2>(a) == get<2>(b) && get<0>(a) < get<0>(b))));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int u, n;
	cin >> u >> n;
	vector<tuple<int, string, int>> auctions;
	auctions.resize(n);
	for(int i = 0; i < n; ++i){
		string name;
		int price;
		cin >> name >> price;
		auctions[i] = make_tuple(i, name, price);
		if(cnt.find(price) == cnt.end()){
			cnt[price] = 1;
		}else{
			++cnt[price];
		}
	}
	sort(auctions.begin(), auctions.end(), cmp);
	cout << get<1>(auctions[0]) << ' ' << get<2>(auctions[0]);
	return 0;
}
