#include <iostream>
#include <vector>

using namespace std;

int parametric_search(vector<int> &y_idx, int m, int val){
	int low = 0, high = m;
	while(low < high){
		int mid = (low + high) / 2;
		if(y_idx[mid] >= val){
   			high = mid;
		}else{
			low = mid + 1;
		}
	}
	return low;
}

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	vector<long long> x, y;
	vector<int> x_idx, y_idx;
	int n;
	cin >> n;
	x.resize(n);
	x_idx.resize(n);
	for(int i = 0; i < n; ++i){
		cin >> x_idx[i] >> x[i];
	}
	int m;
	cin >> m;
	y.resize(m);
	y_idx.resize(m);
	for(int j = 0; j < m; ++j){
		cin >> y_idx[j] >> y[j];
	}
	vector<long long> y_sum(m + 1);
	for(int j = 0; j < m; ++j){
		y_sum[j + 1] = y_sum[j] + y[j];
	}
	int a, b;
	cin >> a >> b;
	long long ans = 0;
	for(int i = 0; i < n; ++i){
		int low = parametric_search(y_idx, m, x_idx[i] + a);
		int high = parametric_search(y_idx, m, x_idx[i] + b + 1);
		ans += x[i] * (y_sum[high] - y_sum[low]);
	}
	cout << ans;
	return 0;
}
