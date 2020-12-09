#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <tuple>

using namespace std;

double dist(double x1, double y1, double x2, double y2){
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, t;
	cin >> n >> t;
	vector<tuple<double, double, int>> v(n);
	for(int i = 0; i < n; ++i){
		cin >> get<0>(v[i]) >> get<1>(v[i]) >> get<2>(v[i]);
	}
	double actual = 0;
	for(int i = 1; i < n; ++i){
		actual += dist(get<0>(v[i]), get<1>(v[i]), get<0>(v[i - 1]), get<1>(v[i - 1]));
	}
	int end = get<2>(v[n - 1]);
	int idx = 1;
	vector<tuple<double, double, int>> w;
	for(int time = 0; time <= end; time += t){
		while(idx < n && get<2>(v[idx]) < time){
			++idx;
		}
		double x = (get<0>(v[idx - 1]) * (get<2>(v[idx]) - time) + get<0>(v[idx]) * (time - get<2>(v[idx - 1]))) / (get<2>(v[idx]) - get<2>(v[idx - 1]));
		double y = (get<1>(v[idx - 1]) * (get<2>(v[idx]) - time) + get<1>(v[idx]) * (time - get<2>(v[idx - 1]))) / (get<2>(v[idx]) - get<2>(v[idx - 1]));
		w.push_back(make_tuple(x, y, time));
	}
	w.push_back(v.back());
	double gps = 0;
	for(unsigned j = 1; j < w.size(); ++j){
		gps += dist(get<0>(w[j]), get<1>(w[j]), get<0>(w[j - 1]), get<1>(w[j - 1]));
	}
	cout << setprecision(11) << fixed << (actual - gps) / actual * 100;
	return 0;
}
