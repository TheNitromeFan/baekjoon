#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	m += n;
	double ans = 0;
	int j = 0;
	for(int i = 0; i < n; ++i){
		while((j + 1) * n < i * m){
			++j;
		}
		ans += 10000.0 * min(i * m - j * n, (j + 1) * n - i * m) / (n * m);
	}
	cout << setprecision(6) << fixed << ans;
	return 0;
}
