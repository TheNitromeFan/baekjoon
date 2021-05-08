#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int dist(int x1, int y1, int x2, int y2){
	return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

int ccw(int x1, int y1, int x2, int y2, int x3, int y3){
	int cmp = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
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
		vector<tuple<int, int, int>> points(n);
		for(int i = 0; i < n; ++i){
			get<0>(points[i]) = i;
			cin >> get<1>(points[i]) >> get<2>(points[i]);
		}
		sort(points.begin(), points.end(), [](tuple<int, int, int> a, tuple<int, int, int> b){
			int ax = get<1>(a), ay = get<2>(a), bx = get<1>(b), by = get<2>(b);
			return ax < bx || (ax == bx && ay < by);
		});
		sort(points.begin() + 1, points.end(), [&](tuple<int, int, int> a, tuple<int, int, int> b){
			int px = get<1>(points[0]), py = get<2>(points[0]), ax = get<1>(a), ay = get<2>(a), bx = get<1>(b), by = get<2>(b);
			int cmp = ccw(px, py, ax, ay, bx, by);
			if(cmp > 0){
				return true;
			}else if(cmp < 0){
				return false;
			}else{
				return dist(px, py, ax, ay) < dist(px, py, bx, by);
			}
		});
		int pt = n - 1;
		while(ccw(get<1>(points[0]), get<2>(points[0]),
				get<1>(points[pt - 1]), get<2>(points[pt - 1]),
				get<1>(points[pt]), get<2>(points[pt])) == 0){
			--pt;
		}
		reverse(points.begin() + pt, points.end());
		for(tuple<int, int, int> t : points){
			cout << get<0>(t) << ' ';
		}
		cout << '\n';
	}
	return 0;
}
