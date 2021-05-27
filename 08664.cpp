#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<pair<int, int>> p(4);
	for(int i = 0; i < 4; ++i){
		cin >> p[i].first >> p[i].second;
	}
	sort(p.begin(), p.end());
	cout << ((p[0].first == p[1].first && p[2].first == p[3].first
	&& p[0].second == p[2].second && p[1].second && p[3].second
	&& p[1].second - p[0].second > 0
	&& p[1].second - p[0].second == p[2].first - p[0].first) ? "TAK" : "NIE");
	return 0;
}
