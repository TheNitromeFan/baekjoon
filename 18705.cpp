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
	for(int i = 0; i < t; ++i){
		int n;
		cin >> n;
		cout << setprecision(7) << fixed << 1e4 / (1 - cos(PI / n) * cos(PI / n)) << '\n';
	}
	return 0;
}
