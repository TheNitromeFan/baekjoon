#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

double profit(vector<int> &c, int m, double val){
	double ret = -c[0];
	for(int i = 1; i <= m; ++i){
		ret *= val;
		ret += c[i];
	}
	return ret;
}

double r(vector<int> &c, int m){
	double low = 0, high = 2;
	for(int i = 0; i < 1000; ++i){
		double mid = (low + high) / 2;
		if(profit(c, m, mid) >= 0){
			low = mid;
		}else{
			high = mid;
		}
	}
	return low - 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 1; a0 <= t; ++a0){
		int m;
		cin >> m;
		vector<int> c(m + 1);
		for(int i = 0; i <= m; ++i){
			cin >> c[i];
		}
		cout << setprecision(12) << fixed << "Case #" << a0 << ": " << r(c, m) << "\n";
	}
	return 0;
}
