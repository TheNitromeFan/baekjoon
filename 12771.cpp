#include <iostream>
#include <cmath>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<tuple<int, int, int>> v(n);
	for(int i = 0; i < n; ++i){
		int x1, x2, y;
		cin >> x1 >> x2 >> y;
		if(x1 > x2){
			swap(x1, x2);
		}
		v[i] = make_tuple(x1, x2, y);
	}
	long long ans = 0;
	for(int i = 0; i < n; ++i){
		int x, y;
		long long cmp = 0;
		vector<tuple<double, double, int>> w;
		unsigned idx1;
		x = get<0>(v[i]);
		y = get<2>(v[i]);
		w.clear();
		for(int j = 0; j < n; ++j){
			int x1 = get<0>(v[j]), x2 = get<1>(v[j]), y1 = get<2>(v[j]);
			if(y1 == y){
				continue;
			}else if(y1 > y){
				w.push_back(make_tuple(atan((x1 - x) / (double)(y1 - y)), atan((x2 - x) / (double)(y1 - y)), x2 - x1));
			}else{
				w.push_back(make_tuple(atan((x - x2) / (double)(y - y1)), atan((x - x1) / (double)(y - y1)), x2 - x1));
			}
		}
		sort(w.begin(), w.end());
		cmp = get<1>(v[i]) - get<0>(v[i]);
		ans = max(ans, cmp);
		idx1 = 0;
		for(unsigned idx2 = 0; idx2 < w.size(); ++idx2){
			double cur = get<0>(w[idx2]);
			while(idx1 < w.size() && get<1>(w[idx1]) < cur){
				cmp -= get<2>(w[idx1]);
				++idx1;
			}
			cmp += get<2>(w[idx2]);
			ans = max(ans, cmp);
		}
		x = get<1>(v[i]);
		y = get<2>(v[i]);
		w.clear();
		for(int j = 0; j < n; ++j){
			int x1 = get<0>(v[j]), x2 = get<1>(v[j]), y1 = get<2>(v[j]);
			if(y1 == y){
				continue;
			}else if(y1 > y){
				w.push_back(make_tuple(atan((x1 - x) / (double)(y1 - y)), atan((x2 - x) / (double)(y1 - y)), x2 - x1));
			}else{
				w.push_back(make_tuple(atan((x - x2) / (double)(y - y1)), atan((x - x1) / (double)(y - y1)), x2 - x1));
			}
		}
		sort(w.begin(), w.end());
		cmp = get<1>(v[i]) - get<0>(v[i]);
		ans = max(ans, cmp);
		idx1 = 0;
		for(unsigned idx2 = 0; idx2 < w.size(); ++idx2){
			double cur = get<0>(w[idx2]);
			while(idx1 < w.size() && get<1>(w[idx1]) < cur){
				cmp -= get<2>(w[idx1]);
				++idx1;
			}
			cmp += get<2>(w[idx2]);
			ans = max(ans, cmp);
		}
	}
	cout << ans;
	return 0;
}
