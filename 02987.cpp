#include <cstdio>
#include <cstdlib>
#include <utility>
#include <algorithm>

using namespace std;

int ccw(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3){
	return p1.first * (p2.second - p3.second) + p2.first * (p3.second - p1.second) + p3.first * (p1.second - p2.second);
}

int main(){
	pair<int, int> p1, p2, p3;
	scanf("%d %d %d %d %d %d", &p1.first, &p1.second, &p2.first, &p2.second, &p3.first, &p3.second);
	if(ccw(p1, p2, p3) < 0){
		swap(p1, p3);
	}
	printf("%.1f\n", ccw(p1, p2, p3) / 2.0);
	int n;
	scanf("%d", &n);
	int ans = 0;
	for(int i = 0; i < n; ++i){
		int x, y;
		scanf("%d %d", &x, &y);
		pair<int, int> p = make_pair(x, y);
		if(ccw(p1, p2, p) >= 0 && ccw(p2, p3, p) >= 0 && ccw(p3, p1, p) >= 0){
			++ans;
		}
	}
	printf("%d", ans);
	return 0;
}
