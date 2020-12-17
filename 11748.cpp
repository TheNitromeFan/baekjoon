#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> cylinders(n);
	for(int i = 0; i < n; ++i){
		cin >> cylinders[i];
	}
	vector<double> x(n);
	for(int i = 0; i < n; ++i){
		x[i] = 0;
		for(int j = 0; j < i; ++j){
			x[i] = max(x[i], x[j] + 2 * sqrt(cylinders[j] * cylinders[i]));
		}
	}
	double start = 0, end = 0;
	for(int i = 0; i < n; ++i){
		start = min(start, x[i] - cylinders[i]);
		end = max(end, x[i] + cylinders[i]);
	}
	cout << setprecision(11) << fixed << end - start;
	return 0;
}
