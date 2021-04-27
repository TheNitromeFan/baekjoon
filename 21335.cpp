#include <iostream>
#include <cmath>
#include <iomanip>
#define PI acos(-1)

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long a;
	cin >> a;
	cout << fixed << setprecision(12) << 2 * PI * sqrt(a / PI);
	return 0;
}
