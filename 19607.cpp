#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> obs(n);
	for(int i = 0; i < n; ++i){
		cin >> obs[i].first >> obs[i].second;
	}
	sort(obs.begin(), obs.end());
	double max_speed = 0;
	for(int i = 0; i + 1 < n; ++i){
		double speed = abs(obs[i + 1].second - obs[i].second) / (double)(obs[i + 1].first - obs[i].first);
		if(max_speed < speed){
			max_speed = speed;
		}
	}
	cout << fixed << setprecision(9) << max_speed;
	return 0;
}
