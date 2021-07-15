#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	cin >> k;
	for(int a0 = 1; a0 <= k; ++a0){
		int left, right, n;
		cin >> left >> right >> n;
		vector<double> y(n);
		for(int i = 0; i < n; ++i){
			cin >> y[i];
		}
		sort(y.begin(), y.end(), greater<double>());
		double sum = 0;
		for(int i = 0; i < left; ++i){
			sum += y[i];
		}
		for(int i = left; i < n; ++i){
			sum += 1 - y[i];
		}
		double max_sum = sum;
		for(int i = left; i < right; ++i){
			sum += 2 * y[i] - 1;
			max_sum = max(max_sum, sum);
		}
		cout << "Data Set " << a0 << ":\n";
		cout << fixed << setprecision(2) << max_sum << "\n";
	}
	return 0;
}
