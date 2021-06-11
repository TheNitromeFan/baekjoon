#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<long long> x(n), y(n);
	for(int i = 0; i < n; ++i){
		cin >> x[i] >> y[i];
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	long long dist = 0;
	for(int i = 0; i < n; ++i){
		dist += x[i] * (2 * i + 1 - n);
		dist += y[i] * (2 * i + 1 - n);
	}
	cout << dist << '\n';
	return 0;
}
