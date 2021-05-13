#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

long long dist(pair<long long, long long> a, pair<long long, long long> b){
	int ax = a.first, ay = a.second, bx = b.first, by = b.second;
	return (bx - ax) * (bx - ax) + (by - ay) * (by - ay);
}

int ccw(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c){
	long long ax = a.first, ay = a.second, bx = b.first, by = b.second, cx = c.first, cy = c.second;
	long long cmp = (bx - ax) * (cy - ay) - (cx - ax) * (by - ay);
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
	int n;
	cin >> n;
	vector<pair<long long, long long>> hull;
	for(int a0 = 0; a0 < n; ++a0){
		long long x, y;
		char inc;
		cin >> x >> y >> inc;
		if(inc == 'Y'){
			hull.push_back(make_pair(x, y));
		}
	}
	sort(hull.begin(), hull.end());
	sort(hull.begin() + 1, hull.end(), [&](pair<long long, long long> a, pair<long long, long long> b){
		pair<long long, long long> p = hull[0];
		int cmp = ccw(p, a, b);
		if(cmp > 0){
			return true;
		}else if(cmp < 0){
			return false;
		}else{
			return dist(p, a) < dist(p, b);
		}
	});
	unsigned pt = hull.size() - 1;
	while(ccw(hull[0], hull[pt - 1], hull[pt]) == 0){
		--pt;
	}
	reverse(hull.begin() + pt, hull.end());
	cout << hull.size() << '\n';
	for(pair<long long, long long> xy : hull){
		cout << xy.first << ' ' << xy.second << '\n';
	}
	return 0;
}
