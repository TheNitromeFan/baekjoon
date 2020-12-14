#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3){
	long long cmp = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
	if(cmp > 0){
		return 1;
	}else if(cmp < 0){
		return -1;
	}else{
		return 0;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		cin >> n;
		vector<pair<long long, long long>> p(n);
		for(int i = 0; i < n; ++i){
			cin >> p[i].first >> p[i].second;
		}
		sort(p.begin(), p.end(), [](pair<long long, long long> a, pair<long long, long long> b){
			return a.second > b.second || (a.second == b.second && a.first < b.first);
		});
		sort(p.begin() + 1, p.end(), [&p](pair<long long, long long> a, pair<long long, long long> b){
			int cmp = ccw(p[0].first, p[0].second, a.first, a.second, b.first, b.second);
			return (cmp < 0) || (cmp == 0 && a.second > b.second)
			|| (cmp == 0 && a.second == b.second && a.first < b.first);
		});
		vector<pair<long long, long long>> hull;
		hull.push_back(p[0]);
		hull.push_back(p[1]);
		for(int i = 2; i < n; ++i){
			while(hull.size() >= 2){
				pair<long long, long long> b = hull.back();
				hull.pop_back();
				pair<long long, long long> a = hull.back();
				if(ccw(a.first, a.second, b.first, b.second, p[i].first, p[i].second) < 0){
					hull.push_back(b);
					break;
				}
			}
			hull.push_back(p[i]);
		}
		cout << hull.size() << '\n';
		for(pair<long long, long long> x : hull){
			cout << x.first << ' ' << x.second << '\n';
		}
	}
	return 0;
}
