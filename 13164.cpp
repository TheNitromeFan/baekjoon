#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	static int h[300000];
	for(int i = 0; i < n; ++i){
		cin >> h[i];
	}
	int sum = h[n - 1] - h[0];
	static int diff[299999];
	for(int i = 0; i + 1 < n; ++i){
		diff[i] = h[i + 1] - h[i];
	}
	sort(diff, diff + n - 1, greater<int>());
	for(int i = 0; i < k - 1; ++i){
		sum -= diff[i];
	}
	cout << sum;
	return 0;
}
