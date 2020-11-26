#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	long long sum1 = 0, sum2 = 0;
	for(int i = 0; i < n; ++i){
		cin >> v[i];
		sum1 += v[i];
	}
	sort(v.begin(), v.end(), greater<int>());
	sum2 = v[0];
	double maxA = 100.0 / n;
	double maxB = v[0] * 100.0 / sum1;
	for(int i = 1; i < n; ++i){
		sum2 += v[i];
		double a = (i + 1) * 100.0 / n;
		double b = sum2 * 100.0 / sum1;
		if(maxB - maxA < b - a){
			maxB = b;
			maxA = a;
		}
	}
	cout << fixed << setprecision(10) << maxA << '\n' << maxB;
	return 0;
}
