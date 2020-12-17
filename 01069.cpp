#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x, y, d, t;
	cin >> x >> y >> d >> t;
	double dist = sqrt(x * x + y * y);
	double time = min(dist, t + abs(dist - d));
	for(int i = 2; i <= 10000; ++i){
		if(dist > d * i){
			time = min(time, t * i + (dist - d * i));
		}else{
			time = min(time, (double)t * i);
		}
	}
	cout << setprecision(11) << fixed << time;
	return 0;
}
