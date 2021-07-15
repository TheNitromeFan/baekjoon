#include <iostream>
#include <cmath>
#include <iomanip>
#define PI acos(-1)

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int r, R, n;
	cin >> r >> R >> n;
	double ans = (n / 2) * (2 * PI / n * R) + ((n - 1) / 2) * (2 * PI / n * (R - r)) + n * (PI / 2 * r);
	if(n == 2){
		ans = PI * R + PI / 2 * r;
	}
	cout << fixed << setprecision(12) << ans << '\n';
	return 0;
}
