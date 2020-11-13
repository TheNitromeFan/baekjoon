#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> points;
	points.resize(n);
	for(int i = 0; i < n; ++i){
		scanf("%d %d", &points[i].first, &points[i].second);
	}
	sort(points.begin(), points.end());
	int ans = 0;
	for(int i = 0; i < n; ++i){
		if(i == 0){
			int k = 1;
			while(k < n && points[k].second != points[0].second){
				++k;
			}
			if(k < n){
				ans += points[k].first - points[0].first;
			}
			continue;
		}else if(i == n - 1){
			int j = n - 2;
			while(j >= 0 && points[j].second != points[n - 1].second){
				--j;
			}
			if(j >= 0){
				ans += points[n - 1].first - points[j].first;
			}
			continue;
		}
		int j = i - 1, k = i + 1;
		while(j >= 0 && k < n && points[j].second != points[i].second && points[k].second != points[i].second){
			if(j == 0){
				++k;
			}else if(k == n - 1){
				--j;
			}else if(points[i].first - points[j].first < points[k].first - points[i].first){
				--j;
			}else if(points[i].first - points[j].first > points[k].first - points[i].first){
				++k;
			}else{
				--j;
				++k;
			}
		}
		if(points[j].second == points[i].second && points[k].second == points[i].second){
			ans += min(points[i].first - points[j].first, points[k].first - points[i].first);
		}else if(points[j].second == points[i].second){
			ans += points[i].first - points[j].first;
		}else if(points[k].second == points[i].second){
			ans += points[k].first - points[i].first;
		}
	}
	printf("%d", ans);
	return 0;
}
