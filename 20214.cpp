#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unsigned n;
	cin >> n;
	vector<long long> t(n);
	for(unsigned i = 0; i < n; ++i){
		cin >> t[i];
	}
	sort(t.begin(), t.end(), greater<long long>());
	double time = 0;
	long long power_of_two = 1;
	for(unsigned i = 0; i < n; ++i){
		power_of_two *= 2;
		time += (double)t[i] / power_of_two;
	}
	cout << fixed << setprecision(12) << time;
	return 0;
}
