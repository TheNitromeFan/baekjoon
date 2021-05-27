#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

double dist(double x, double y, double z){
	return sqrt(x * x + y * y + z * z);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<double> clouds(n);
	for(int i = 0; i < n; ++i){
		double x, y, z;
		cin >> x >> y >> z;
		clouds[i] = dist(x, y, z);
	}
	sort(clouds.begin(), clouds.end());
	cout << fixed << setprecision(12) << clouds[k - 1];
	return 0;
}
