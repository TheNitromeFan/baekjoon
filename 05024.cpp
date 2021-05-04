#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n, p;
	cin >> n >> p;
	vector<long long> cars(n);
	for(long long i = 0; i < n; ++i){
		cin >> cars[i];
	}
	sort(cars.begin(), cars.end());
	long long x = p;
	for(long long i = 1; i < n; ++i){
		x = max(x, cars[0] - cars[i] + p * (i + 1));
	}
	cout << x;
	return 0;
}
