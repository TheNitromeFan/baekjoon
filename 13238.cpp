#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	vector<int> min(n), max(n);
	min[0] = v[0];
	for(int i = 1; i < n; ++i){
		min[i] = min[i - 1];
		if(min[i] > v[i]){
			min[i] = v[i];
		}
	}
	max[n - 1] = v[n - 1];
	for(int i = n - 2; i >= 0; --i){
		max[i] = max[i + 1];
		if(max[i] < v[i]){
			max[i] = v[i];
		}
	}
	int ans = 0;
	for(int i = 0; i < n; ++i){
		if(ans < max[i] - min[i]){
			ans = max[i] - min[i];
		}
	}
	cout << ans;
	return 0;
}
