#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, p;
	cin >> n >> p;
	int x = n / (p - 1);
	double ans = x * (double)p / (n + 1);
	for(int i = 2; i <= x; ++i){
		ans *= (double)(n - p + i) / (n + i);
	}
	cout << setprecision(9) << fixed << ans;
	return 0;
}
