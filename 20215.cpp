#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int w, h;
	cin >> w >> h;
	cout << fixed << setprecision(12) << w + h - sqrt(w * w + h * h);
	return 0;
}
