#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define PI acos(-1)

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double t;
	cin >> t;
	int b;
	cin >> b;
	vector<int> radii;
	for(int i = 0; i < b; ++i){
		int d, s;
		cin >> d >> s;
		for(int j = 0; j < d; ++j){
			radii.push_back(s);
		}
	}
	sort(radii.begin(), radii.end());
	unsigned cnt = 0;
	while(cnt < radii.size()){
		if(t >= 2 * PI * radii[cnt]){
			t -= 2 * PI * radii[cnt];
			++cnt;
		}else{
			break;
		}
	}
	cout << cnt;
	return 0;
}
