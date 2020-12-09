#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

double cross(double x1, double y1, double x2, double y2, double x3, double y3){
	return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<tuple<double, double, double, double>> segs(n);
	for(int i = 0; i < n; ++i){
		double x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		segs[i] = make_tuple(x1, y1, x2, y2);
	}
	return 0;
}
