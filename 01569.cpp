#include <iostream>
#include <utility>

using namespace std;

bool can_cover(pair<int, int> points[101], int n, int x1, int x2, int y1, int y2){
	for(int i = 0; i < n; ++i){
		int x = points[i].first, y = points[i].second;
		if(!(((y == y1 || y == y2) && (x >= x1 && x <= x2)) || ((x == x1 || x == x2) && (y >= y1 && y <= y2)))){
			return false;
		}
	}
	return true;
}

int cover(pair<int, int> points[101], int n){
	int minX = 1000, maxX = -1000, minY = 1000, maxY = -1000;
	for(int i = 0; i < n; ++i){
		if(points[i].first < minX){
			minX = points[i].first;
		}
		if(points[i].first > maxX){
			maxX = points[i].first;
		}
		if(points[i].second < minY){
			minY = points[i].second;
		}
		if(points[i].second > maxY){
			maxY = points[i].second;
		}
	}
	if(maxY - minY > maxX - minX){
		return can_cover(points, n, minX, minX + maxY - minY, minY, maxY)
		|| can_cover(points, n, maxX - maxY + minY, maxX, minY, maxY) ? maxY - minY : -1;
	}else{
		return can_cover(points, n, minX, maxX, minY, minY + maxX - minX)
		|| can_cover(points, n, minX, maxX, maxY - maxX + minX, maxY) ? maxX - minX : -1;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	pair<int, int> points[101];
	for(int i = 0; i < n; ++i){
		cin >> points[i].first >> points[i].second;
	}
	int ans = cover(points, n);
	cout << ans;
	return 0;
}
