#include <cstdio>
#include <algorithm>

using std::sort;

int main(){
	int n;
	scanf("%d", &n);
	int stop[5000];
	for(int i = 0; i < n; ++i){
		scanf("%d", &stop[i]);
	}
	sort(stop, stop + n);
	int minDist = 2 * 32800000;
	for(int i = 0; i + 1 < n; ++i){
		if(minDist > stop[i + 1] - stop[i]){
			minDist = stop[i + 1] - stop[i];
		}
	}
	int cnt = 0;
	for(int i = 0; i + 1 < n; ++i){
		if(stop[i + 1] - stop[i] == minDist){
			++cnt;
		}
	}
	printf("%d %d", minDist, cnt);
	return 0;
}
