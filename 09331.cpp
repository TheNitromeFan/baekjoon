#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3){
	return (x3 - x1) * (y2 - y1) - (x2 - x1) * (y3 - y1);
}

void top_university(vector<tuple<int, int, int>> &v, int n, vector<bool> &is_top){
	bool colinear = true;
	for(int i = 0; i < n; ++i){
		int xi = get<0>(v[i]), yi = get<1>(v[i]), zi = get<2>(v[i]);
		for(int j = i + 1; j < n; ++j){
			int xj = get<0>(v[j]), yj = get<1>(v[j]), zj = get<2>(v[j]);
			for(int k = j + 1; k < n; ++k){
				int xk = get<0>(v[k]), yk = get<1>(v[k]), zk = get<2>(v[k]);
				int a = ccw(yk, zk, yj, zj, yi, zi);
				int b = ccw(zk, xk, zj, xj, zi, xi);
				int c = ccw(xk, yk, xj, yj, xi, yi);
				if(a || b || c){
					colinear = false;
					for(int l = -1; l <= 1; l += 2){
						int maxval = -2000000000;
						for(int idx = 0; idx < n; ++idx){
							int xidx = get<0>(v[idx]), yidx = get<1>(v[idx]), zidx = get<2>(v[idx]);
							maxval = max(maxval, l * a * xidx + l * b * yidx + l * c * zidx);
						}
						for(int idx = 0; idx < n; ++idx){
							int xidx = get<0>(v[idx]), yidx = get<1>(v[idx]), zidx = get<2>(v[idx]);
							if(maxval == l * a * xidx + l * b * yidx + l * c * zidx){
								is_top[idx] = true;
							}
						}
					}
				}
			}
		}
	}
	if(colinear){
		fill(is_top.begin(), is_top.end(), true);
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
		vector<tuple<int, int, int>> v(n);
		for(int i = 0; i < n; ++i){
			int x, y, z;
			cin >> x >> y >> z;
			v[i] = make_tuple(x, y, z);
		}
		vector<bool> is_top(n);
		top_university(v, n, is_top);
		for(int i = 0; i < n; ++i){
			cout << (is_top[i] ? 'T' : 'F');
		}
		cout << '\n';
	}
	return 0;
}
