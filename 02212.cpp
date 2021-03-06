#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	vector<int> diff(n - 1);
	for(int i = 0; i < n - 1; ++i){
		diff[i] = v[i + 1] - v[i];
	}
	sort(diff.begin(), diff.end(), greater<int>());
	long long sum = 0;
	for(int i = k - 1; i < n - 1; ++i){
		sum += diff[i];
	}
	cout << sum;
	return 0;
}
