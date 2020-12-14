#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double pv = 0;
	double maxV = 0;
	for(int i = 1; i <= 6; ++i){
		double vi;
		cin >> vi;
		pv += i * vi;
		if(vi > maxV){
			maxV = vi;
		}
	}
	cout << setprecision(3) << fixed << abs(pv - 3.5) / maxV;
	return 0;
}
