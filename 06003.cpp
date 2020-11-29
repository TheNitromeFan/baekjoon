#include <iostream>
#include <vector>
#include <utility>

using namespace std;

long long dist(vector<pair<int, int>> &v, int i, int j){
	return (long long)(v[i].first - v[j].first) * (v[i].first - v[j].first)
	+ (long long)(v[i].second - v[j].second) * (v[i].second - v[j].second);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> field(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> field[i].first >> field[i].second;
	}
	long long minDist = 1000000000000000000LL;
	int x = 0, y = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = i + 1; j <= n; ++j){
			long long cmp = dist(field, i, j);
			if(cmp < minDist){
				minDist = cmp;
				x = i;
				y = j;
			}
		}
	}
	cout << x << " " << y;
	return 0;
}
