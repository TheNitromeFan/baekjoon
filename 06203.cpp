#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int next(int x, int n){
	if(x == n){
		return 1;
	}else{
		return x + 1;
	}
}

long long dist(long long x1, long long y1, long long x2, long long y2){
	return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<long long, long long>> cows(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> cows[i].first >> cows[i].second;
	}
	vector<bool> tagged(n + 1);
	int last = 0;
	int cnt = 0;
	for(int i = 1; cnt < n - 1; i = next(i, n)){
		if(tagged[i]){
			continue;
		}
		last = i;
		long long minimal_dist = 2000000000000000000LL;
		int nearest = -1;
		for(int j = 1; j <= n; ++j){
			if(j != i && !tagged[j]
			&& minimal_dist > dist(cows[i].first, cows[i].second, cows[j].first, cows[j].second)){
				minimal_dist = dist(cows[i].first, cows[i].second, cows[j].first, cows[j].second);
				nearest = j;
			}
		}
		// cout << nearest << '\n';
		if(nearest != -1){
			tagged[nearest] = true;
		}
		++cnt;
	}
	cout << last;
	return 0;
}
