#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long a;
	cin >> a;
	cout << fixed << setprecision(12) << 4 * sqrt(a);
	return 0;
}
