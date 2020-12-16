#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double vs, r, c;
	int n;
	cin >> vs >> r >> c >> n;
	for(int i = 0; i < n; ++i){
		double w;
		cin >> w;
		cout << setprecision(3) << fixed << c * w * r * vs / sqrt(abs(1 + c * c * w * w * r * r)) << '\n';
	}
	return 0;
}
