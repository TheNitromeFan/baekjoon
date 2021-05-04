#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<long long> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	long long rolling_sum = 0;
	for(int i = 0; i < k; ++i){
		rolling_sum += v[i];
	}
	long long max = rolling_sum;
	for(int i = k; i < n; ++i){
		rolling_sum += v[i] - v[i - k];
		if(max < rolling_sum){
			max = rolling_sum;
		}
	}
	cout << max;
	return 0;
}
