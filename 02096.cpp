#include <cstdio>
#include <algorithm>

using std::max;
using std::min;

int main(){
	int n;
	scanf("%d", &n);
	int arr[3], dp_max[2][3] = {}, dp_min[2][3] = {};
	for(int j = 0; j < 3; ++j){
		scanf("%d", &arr[j]);
	}
	dp_max[0][0] = arr[0];
	dp_max[0][1] = arr[1];
	dp_max[0][2] = arr[2];
	dp_min[0][0] = arr[0];
	dp_min[0][1] = arr[1];
	dp_min[0][2] = arr[2];
	for(int i = 1; i < n; ++i){
		for(int j = 0; j < 3; ++j){
			scanf("%d", &arr[j]);
		}
		dp_max[1][0] = max(dp_max[0][0], dp_max[0][1]) + arr[0];
		dp_max[1][1] = max(max(dp_max[0][0], dp_max[0][2]), dp_max[0][1]) + arr[1];
		dp_max[1][2] = max(dp_max[0][1], dp_max[0][2]) + arr[2];
		dp_min[1][0] = min(dp_min[0][0], dp_min[0][1]) + arr[0];
		dp_min[1][1] = min(min(dp_min[0][0], dp_min[0][2]), dp_min[0][1]) + arr[1];
		dp_min[1][2] = min(dp_min[0][1], dp_min[0][2]) + arr[2];
		for(int j = 0; j < 3; ++j){
			dp_max[0][j] = dp_max[1][j];
			dp_min[0][j] = dp_min[1][j];
		}
	}
	printf("%d %d", max(max(dp_max[0][0], dp_max[0][2]), dp_max[0][1]), min(min(dp_min[0][0], dp_min[0][2]), dp_min[0][1]));
	return 0;
}
