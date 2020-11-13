#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

int dist(pair<int, int> a, pair<int, int> b){
	if(a > b){
		swap(a, b);
	}
	if(a.second <= b.second){
		return max(b.first - a.first, b.second - a.second);
	}else{
		return b.first - a.first + a.second - b.second;
	}
}

int main(){
	int w, h, n;
	scanf("%d %d %d", &w, &h, &n);
	int x1, y1, x2, y2;
	scanf("%d %d", &x1, &y1);
	int ans = 0;
	for(int i = 1; i < n; ++i){
		scanf("%d %d", &x2, &y2);
		ans += dist(make_pair(x1, y1), make_pair(x2, y2));
		x1 = x2;
		y1 = y2;
	}
	printf("%d", ans);
	return 0;
}
