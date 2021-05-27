#include <iostream>
#include <cmath>
#include <iomanip>
#define PI acos(-1)

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 1; a0 <= t; ++a0){
		double r;
		int n;
		cin >> r >> n;
		double ans = r * sin(PI / n) / (1 + sin(PI / n));
		cout << "Scenario #" << a0 << ":\n" << fixed << setprecision(3) << ans << "\n\n";
	}
	return 0;
}
