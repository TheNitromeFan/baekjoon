#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>
#include <iomanip>

using namespace std;

bool transmit(vector<pair<int, int>> v, int n, double d){
	double low = v[0].first - d, high = v[0].first + d;
	for(int i = 1; i < n; ++i){
		if(v[i].first > v[i - 1].first){
			if(high + v[i].second - v[i - 1].second < v[i].first - d){
				return false;
			}
			high = min(v[i].first + d, high + v[i].second - v[i - 1].second);
			low = v[i].first - d;
		}else{
			if(low - v[i].second + v[i - 1].second > v[i].first + d){
				return false;
			}
			low = max(v[i].first - d, low - v[i].second + v[i - 1].second);
			high = v[i].first + d;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int c;
	cin >> c;
	for(int a0 = 1; a0 <= c; ++a0){
		int n;
		cin >> n;
		vector<pair<int, int>> v(n);
		for(int i = 0; i < n; ++i){
			cin >> v[i].first >> v[i].second;
		}
		sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b){
			return a.second < b.second;
		});
		for(double speed = 0; ; speed += 0.5){
			if(transmit(v, n, speed)){
				cout << "Case #" << a0 << ": " << fixed << setprecision(1) << speed << '\n';
				break;
			}
		}
	}
	return 0;
}
