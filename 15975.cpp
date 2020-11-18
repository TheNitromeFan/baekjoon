#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<int> points[100005];
	for(int i = 0; i < n; ++i){
		int point, color;
		scanf("%d %d", &point, &color);
		points[color].push_back(point);
	}
	long long ans = 0;
	for(int j = 1; j <= n; ++j){
		if(points[j].size() <= 1){
			continue;
		}
		sort(points[j].begin(), points[j].end());
		ans += points[j][1] - points[j][0] + points[j][points[j].size() - 1] - points[j][points[j].size() - 2];
		for(unsigned k = 1; k + 1 < points[j].size(); ++k){
			ans += min(points[j][k + 1] - points[j][k], points[j][k] - points[j][k - 1]);
		}
	}
	printf("%lld", ans);
	return 0;
}
