#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		double w, g, h, r;
		cin >> w >> g >> h >> r;
		cout << setprecision(8) << fixed << sqrt(w * w + (h - g) * (h - g))
		<< ' ' << sqrt(w * w + (h - r + g - r) * (h - r + g - r)) << '\n';
	}
	return 0;
}
