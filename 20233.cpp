#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, x, b, y, t;
	cin >> a >> x >> b >> y >> t;
	cout << a + 21 * max(0, x * (t - 30)) << ' ' << b + 21 * max(0, y * (t - 45));
	return 0;
}
