#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdlib>

using namespace std;

int angle(int h, int m){
	h %= 12;
	int hour_angle = 60 * h + m, minute_angle = 12 * m;
	int angle_difference = abs(hour_angle - minute_angle);
	return min(angle_difference, 720 - angle_difference);
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		vector<pair<int, int>> times(5);
		for(int i = 0; i < 5; ++i){
			scanf(" %d:%d", &times[i].first, &times[i].second);
		}
		sort(times.begin(), times.end(), [](pair<int, int> a, pair<int, int> b){
			int angleA = angle(a.first, a.second), angleB = angle(b.first, b.second);
			return angleA < angleB || (angleA == angleB && a < b);
		});
		/*
		for(int i = 0; i < 5; ++i){
			printf("%02d:%02d %d\n", times[i].first, times[i].second, angle(times[i].first, times[i].second));
		}
		*/
		printf("%02d:%02d\n", times[2].first, times[2].second);
	}
	return 0;
}
