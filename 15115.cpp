#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	int k, p, x;
	cin >> k >> p >> x;
	int n = (int)sqrt(k * p / (double)x);
	double ans = min(k * p / (double)n + x * n, k * p / (double)(n + 1) + x * (n + 1));
	cout << setprecision(3) << fixed << ans;
	return 0;
}
