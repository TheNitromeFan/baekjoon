#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> cows(n);
	for(int i = 0; i < n; ++i){
		scanf("%d %d", &cows[i].first, &cows[i].second);
	}
	sort(cows.begin(), cows.end());
	int r = 10000000;
	for(int i = 0; i + 1 < n; ++i){
		if(cows[i].second != cows[i + 1].second){
			r = min(r, cows[i + 1].first - cows[i].first - 1);
		}
	}
	int cnt = 0;
	int lastInfected = -10000000;
	for(int i = 0; i < n; ++i){
		if(cows[i].second == 1){
			if(cows[i].first - lastInfected > r){
				++cnt;
			}
			lastInfected = cows[i].first;
		}
	}
	printf("%d", cnt);
	return 0;
}
