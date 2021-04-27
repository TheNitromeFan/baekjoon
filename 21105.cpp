#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int a0 = 0; a0 < n; ++a0){
		double p, c;
		cin >> p >> c;
		cout << fixed << setprecision(12) << 100 * p / (100 + c) << '\n';
	}
	return 0;
}
