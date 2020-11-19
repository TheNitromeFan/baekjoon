#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int h, m, s;
		cin >> h >> m >> s;
		vector<int> angles = {60 * 60 * h + 60 * m + s, 60 * 12 * m + 12 * s, 60 * 12 * s};
		sort(angles.begin(), angles.end());
		cout << fixed << setprecision(9) << min(min(angles[1] - angles[0], angles[2] - angles[1]), 60 * 60 * 12 + angles[0] - angles[2]) / double(60 * 60 * 12 / 360) << '\n';
		// range 0 ~ 60 * 60 * 12
	}
	return 0;
}
